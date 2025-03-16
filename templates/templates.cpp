#include <iostream>
#include <string>

// 1. Função Template
template <typename T>
T soma(T a, T b)
{
    return a + b;
}

// 2. Classe Template
template <typename T>
class Caixa
{
public:
    Caixa(T valor) : valor(valor) {}

    void exibir() const
    {
        std::cout << "Valor na caixa: " << valor << "\n";
    }

private:
    T valor;
};

// 3. Especialização de Template para o tipo const char*
template <>
class Caixa<const char *>
{
public:
    Caixa(const char *valor) : valor(valor) {}

    void exibir() const
    {
        std::cout << "Valor na caixa (especializado para const char*): " << valor << "\n";
    }

private:
    const char *valor;
};

// 4. Metaprogramação com Templates: Calculando fatorial em tempo de compilação
template <int N>
struct Fatorial
{
    static const int valor = N * Fatorial<N - 1>::valor;
};

// Caso base da metaprogramação
template <>
struct Fatorial<0>
{
    static const int valor = 1;
};

int main()
{
    // 1. Usando função template
    std::cout << "Soma de inteiros: " << soma(5, 3) << "\n";
    std::cout << "Soma de doubles: " << soma(3.5, 2.7) << "\n";
    std::cout << "Soma de strings: " << soma(std::string("Hello, "), std::string("World!")) << "\n";

    // 2. Usando classe template
    Caixa<int> caixaInt(42);
    caixaInt.exibir();

    Caixa<double> caixaDouble(3.14);
    caixaDouble.exibir();

    Caixa<std::string> caixaString("Template");
    caixaString.exibir();

    // 3. Usando especialização de template
    Caixa<const char *> caixaChar("Especialização");
    caixaChar.exibir();

    // 4. Usando metaprogramação com templates
    std::cout << "Fatorial de 5: " << Fatorial<5>::valor << "\n";
    std::cout << "Fatorial de 10: " << Fatorial<10>::valor << "\n";

    return 0;
}