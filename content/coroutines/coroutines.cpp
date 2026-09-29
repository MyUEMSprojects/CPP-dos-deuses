#include <iostream>
#include <coroutine>

// Coroutines (C++20): funções que podem suspender sua execução (co_await,
// co_yield) e retomar depois de onde pararam. Aqui usamos co_yield para
// implementar um gerador preguiçoso (lazy) de valores — o próximo valor só
// é calculado quando alguém pede o próximo, em vez de gerar tudo de uma vez
// em um vector.

template <typename T>
class Generator
{
public:
    struct promise_type
    {
        T currentValue;

        // Suspende ANTES do primeiro valor: nada roda até o primeiro resume().
        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }

        // co_yield value; chama isso, guarda o valor e suspende de novo.
        std::suspend_always yield_value(T value)
        {
            currentValue = value;
            return {};
        }

        Generator get_return_object()
        {
            return Generator{std::coroutine_handle<promise_type>::from_promise(*this)};
        }

        void return_void() {}
        void unhandled_exception() { std::terminate(); }
    };

    using Handle = std::coroutine_handle<promise_type>;

    explicit Generator(Handle handle) : handle_(handle) {}
    ~Generator()
    {
        if (handle_)
        {
            handle_.destroy();
        }
    }

    Generator(const Generator &) = delete;
    Generator &operator=(const Generator &) = delete;

    Generator(Generator &&other) noexcept : handle_(other.handle_)
    {
        other.handle_ = nullptr;
    }

    // Sentinela simples para marcar o "fim" do range no for-range
    struct Sentinel
    {
    };

    struct Iterator
    {
        Handle handle;

        bool operator!=(Sentinel) const { return !handle.done(); }
        Iterator &operator++()
        {
            handle.resume();
            return *this;
        }
        T operator*() const { return handle.promise().currentValue; }
    };

    // begin() já avança até o primeiro valor produzido pela coroutine
    Iterator begin()
    {
        handle_.resume();
        return Iterator{handle_};
    }

    Sentinel end() { return {}; }

private:
    Handle handle_;
};

// Gerador de uma sequência [start, end) sem alocar nenhum container
Generator<int> range(int start, int end)
{
    for (int i = start; i < end; ++i)
    {
        co_yield i;
    }
}

// Gerador infinito (!) dos primeiros números de Fibonacci. Como é
// preguiçoso, só calculamos quantos termos realmente pedirmos no main().
Generator<long long> fibonacci()
{
    long long a = 0, b = 1;
    while (true)
    {
        co_yield a;
        long long next = a + b;
        a = b;
        b = next;
    }
}

int main()
{
    std::cout << "range(1, 6): ";
    for (int value : range(1, 6))
    {
        std::cout << value << " ";
    }
    std::cout << "\n";

    std::cout << "Primeiros 10 números de Fibonacci (gerador infinito, cortado manualmente): ";
    int count = 0;
    for (long long value : fibonacci())
    {
        if (count++ >= 10)
        {
            break; // o destrutor de Generator libera a coroutine normalmente
        }
        std::cout << value << " ";
    }
    std::cout << "\n";

    return 0;
}
