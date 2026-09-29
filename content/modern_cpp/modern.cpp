#include <iostream>
#include <vector>
#include <tuple>
#include <type_traits> // Para std::is_integral
#include <coroutine>   // Para coroutines (C++20)

// 1. auto e decltype
auto sum(auto a, auto b) -> decltype(a + b)
{
    return a + b;
}

// 2. Range-based for loops
void rangeBasedForExample()
{
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    for (const auto &num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

// 3. Lambda expressions
void lambdaExample()
{
    auto square = [](int x)
    { return x * x; };
    std::cout << "Quadrado de 5: " << square(5) << "\n";
}

// 4. constexpr e if constexpr
constexpr int factorial(int n)
{
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

template <typename T>
void checkType(T value)
{
    if constexpr (std::is_integral_v<T>)
    {
        std::cout << "Tipo integral: " << value << "\n";
    }
    else
    {
        std::cout << "Tipo não integral.\n";
    }
}

// 5. Structured bindings
void structuredBindingsExample()
{
    std::tuple<int, std::string, double> tup(42, "Hello", 3.14);
    auto [number, text, value] = tup; // Desestruturação
    std::cout << "Número: " << number << ", Texto: " << text << ", Valor: " << value << "\n";
}

// 6. Concepts (C++20)
template <typename T>
concept Integral = std::is_integral_v<T>;

template <Integral T>
T doubleValue(T value)
{
    return value * 2;
}

// 7. Modules (C++20) - Exemplo básico (requer suporte do compilador)
// Módulo seria definido em um arquivo separado (ex: module.cppm)
/*
export module my_module;

export int multiply(int a, int b) {
    return a * b;
}
*/

// 8. Coroutines (C++20)
struct CoroutineExample
{
    struct promise_type
    {
        CoroutineExample get_return_object()
        {
            return CoroutineExample{std::coroutine_handle<promise_type>::from_promise(*this)};
        }
        // 'suspend_always' no início: a coroutine não roda nada até o
        // primeiro resume() explícito (execução "preguiçosa").
        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        void return_void() {}
        void unhandled_exception() { std::terminate(); }
    };

    std::coroutine_handle<promise_type> handle;

    explicit CoroutineExample(std::coroutine_handle<promise_type> h) : handle(h) {}
    ~CoroutineExample()
    {
        if (handle)
        {
            handle.destroy();
        }
    }

    // Sem cópia (dono único do handle); poderíamos adicionar move se necessário.
    CoroutineExample(const CoroutineExample &) = delete;
    CoroutineExample &operator=(const CoroutineExample &) = delete;

    bool resume()
    {
        if (handle && !handle.done())
        {
            handle.resume();
        }
        return handle && !handle.done();
    }
};

CoroutineExample coroutineExample()
{
    std::cout << "Coroutine iniciada.\n";
    co_await std::suspend_always{};
    std::cout << "Coroutine continuada.\n";
}

int main()
{
    // 1. auto e decltype
    std::cout << "Soma de 3 e 4.5: " << sum(3, 4.5) << "\n";

    // 2. Range-based for loops
    std::cout << "Range-based for loop:\n";
    rangeBasedForExample();

    // 3. Lambda expressions
    std::cout << "Lambda expression:\n";
    lambdaExample();

    // 4. constexpr e if constexpr
    std::cout << "Fatorial de 5 (constexpr): " << factorial(5) << "\n";
    checkType(10);   // Tipo integral
    checkType(3.14); // Tipo não integral

    // 5. Structured bindings
    std::cout << "Structured bindings:\n";
    structuredBindingsExample();

    // 6. Concepts (C++20)
    std::cout << "Dobrar (concepts): " << doubleValue(10) << "\n";

    // 7. Modules (C++20) - Exemplo básico (requer suporte do compilador)
    // int result = multiply(3, 4);
    // std::cout << "Multiplicar (modules): " << result << "\n";

    // 8. Coroutines (C++20)
    // Como initial_suspend() é suspend_always, é preciso chamar resume()
    // explicitamente para a coroutine avançar até o próximo ponto de
    // suspensão (co_await) a cada chamada.
    std::cout << "Coroutines:\n";
    auto coro = coroutineExample();
    coro.resume(); // executa até o co_await -> imprime "Coroutine iniciada."
    coro.resume(); // retoma após o co_await -> imprime "Coroutine continuada."

    return 0;
}
