#include <iostream>
#include <vector>
#include <tuple>
#include <type_traits> // Para std::is_integral
#include <coroutine>   // Para coroutines (C++20)

// 1. auto e decltype
auto soma(auto a, auto b) -> decltype(a + b)
{
    return a + b;
}

// 2. Range-based for loops
void exemploRangeBasedFor()
{
    std::vector<int> numeros = {1, 2, 3, 4, 5};
    for (const auto &num : numeros)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

// 3. Lambda expressions
void exemploLambda()
{
    auto quadrado = [](int x)
    { return x * x; };
    std::cout << "Quadrado de 5: " << quadrado(5) << "\n";
}

// 4. constexpr e if constexpr
constexpr int fatorial(int n)
{
    if (n <= 1)
        return 1;
    return n * fatorial(n - 1);
}

template <typename T>
void verificarTipo(T valor)
{
    if constexpr (std::is_integral_v<T>)
    {
        std::cout << "Tipo integral: " << valor << "\n";
    }
    else
    {
        std::cout << "Tipo não integral.\n";
    }
}

// 5. Structured bindings
void exemploStructuredBindings()
{
    std::tuple<int, std::string, double> tupla(42, "Hello", 3.14);
    auto [numero, texto, valor] = tupla; // Desestruturação
    std::cout << "Número: " << numero << ", Texto: " << texto << ", Valor: " << valor << "\n";
}

// 6. Concepts (C++20)
template <typename T>
concept Integral = std::is_integral_v<T>;

template <Integral T>
T dobrar(T valor)
{
    return valor * 2;
}

// 7. Modules (C++20) - Exemplo básico (requer suporte do compilador)
// Módulo seria definido em um arquivo separado (ex: modulo.cppm)
/*
export module modulo;

export int multiplicar(int a, int b) {
    return a * b;
}
*/

// 8. Coroutines (C++20)
struct CoroutineExemplo
{
    struct promise_type
    {
        CoroutineExemplo get_return_object() { return {}; }
        std::suspend_never initial_suspend() { return {}; }
        std::suspend_never final_suspend() noexcept { return {}; }
        void return_void() {}
        void unhandled_exception() {}
    };

    std::coroutine_handle<promise_type> handle;
};

CoroutineExemplo exemploCoroutine()
{
    std::cout << "Coroutine iniciada.\n";
    co_await std::suspend_always{};
    std::cout << "Coroutine continuada.\n";
}

int main()
{
    // 1. auto e decltype
    std::cout << "Soma de 3 e 4.5: " << soma(3, 4.5) << "\n";

    // 2. Range-based for loops
    std::cout << "Range-based for loop:\n";
    exemploRangeBasedFor();

    // 3. Lambda expressions
    std::cout << "Lambda expression:\n";
    exemploLambda();

    // 4. constexpr e if constexpr
    std::cout << "Fatorial de 5 (constexpr): " << fatorial(5) << "\n";
    verificarTipo(10);   // Tipo integral
    verificarTipo(3.14); // Tipo não integral

    // 5. Structured bindings
    std::cout << "Structured bindings:\n";
    exemploStructuredBindings();

    // 6. Concepts (C++20)
    std::cout << "Dobrar (concepts): " << dobrar(10) << "\n";

    // 7. Modules (C++20) - Exemplo básico (requer suporte do compilador)
    // int resultado = multiplicar(3, 4);
    // std::cout << "Multiplicar (modules): " << resultado << "\n";

    // 8. Coroutines (C++20)
    std::cout << "Coroutines:\n";
    auto coroutine = exemploCoroutine();
    (void)coroutine; // Evitar aviso de variável não utilizada

    return 0;
}