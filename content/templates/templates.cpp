#include <iostream>
#include <string>

// 1. Função Template
template <typename T>
T sum(T a, T b)
{
    return a + b;
}

// 2. Classe Template
template <typename T>
class Box
{
public:
    Box(T value) : value(value) {}

    void display() const
    {
        std::cout << "Valor na caixa: " << value << "\n";
    }

private:
    T value;
};

// 3. Especialização de Template para o tipo const char*
template <>
class Box<const char *>
{
public:
    Box(const char *value) : value(value) {}

    void display() const
    {
        std::cout << "Valor na caixa (especializado para const char*): " << value << "\n";
    }

private:
    const char *value;
};

// 4. Metaprogramação com Templates: Calculando fatorial em tempo de compilação
template <int N>
struct Factorial
{
    static const int value = N * Factorial<N - 1>::value;
};

// Caso base da metaprogramação
template <>
struct Factorial<0>
{
    static const int value = 1;
};

int main()
{
    // 1. Usando função template
    std::cout << "Soma de inteiros: " << sum(5, 3) << "\n";
    std::cout << "Soma de doubles: " << sum(3.5, 2.7) << "\n";
    std::cout << "Soma de strings: " << sum(std::string("Hello, "), std::string("World!")) << "\n";

    // 2. Usando classe template
    Box<int> intBox(42);
    intBox.display();

    Box<double> doubleBox(3.14);
    doubleBox.display();

    Box<std::string> stringBox("Template");
    stringBox.display();

    // 3. Usando especialização de template
    Box<const char *> charBox("Especialização");
    charBox.display();

    // 4. Usando metaprogramação com templates
    std::cout << "Fatorial de 5: " << Factorial<5>::value << "\n";
    std::cout << "Fatorial de 10: " << Factorial<10>::value << "\n";

    return 0;
}
