#include <iostream>
#include <string>
#include <concepts>

// Concepts (C++20): restringem os tipos aceitos por um template em tempo
// de compilação, dando erros de compilação muito mais claros do que os
// clássicos "wall of text" de erros de template mal-formado.

// 1. Concept simples combinando concepts da biblioteca padrão
template <typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

// 2. Concept definido com uma requires-expression: exige que a expressão
// `a + b` seja válida e que o tipo resultante seja o próprio T.
template <typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> std::same_as<T>;
};

// 3. Função com template abreviado + concept (equivalente a
// `template <Numeric T> T doubleValue(T value)`)
Numeric auto doubleValue(Numeric auto value)
{
    return value * 2;
}

// 4. Função restrita por 'requires' explícito
template <typename T>
    requires Addable<T>
T sum(T a, T b)
{
    return a + b;
}

// 5. Concepts também funcionam para restringir classes/estruturas
template <typename T>
concept Printable = requires(std::ostream &os, T value) {
    { os << value } -> std::same_as<std::ostream &>;
};

template <Printable T>
void printLabeled(const std::string &label, const T &value)
{
    std::cout << label << ": " << value << "\n";
}

// 6. Sobrecarga por concept: o compilador escolhe a versão certa conforme
// o tipo satisfaça (ou não) o concept — sem SFINAE manual.
template <std::integral T>
void describe(T value)
{
    std::cout << value << " é um inteiro.\n";
}

template <std::floating_point T>
void describe(T value)
{
    std::cout << value << " é ponto flutuante.\n";
}

int main()
{
    std::cout << "doubleValue(21) = " << doubleValue(21) << "\n";
    std::cout << "doubleValue(1.5) = " << doubleValue(1.5) << "\n";

    std::cout << "sum(2, 3) = " << sum(2, 3) << "\n";
    std::cout << "sum(std::string(\"foo\"), std::string(\"bar\")) = "
              << sum(std::string("foo"), std::string("bar")) << "\n";

    printLabeled("Idade", 30);
    printLabeled("Pi", 3.14159);

    describe(10);   // chama a sobrecarga std::integral
    describe(10.0); // chama a sobrecarga std::floating_point

    // As linhas abaixo não compilariam, e é exatamente esse o ponto dos
    // concepts: o erro aparece na chamada, apontando para a restrição
    // violada, em vez de um erro obscuro dentro da implementação do template.
    // doubleValue(std::string("nope")); // erro: std::string não satisfaz Numeric

    return 0;
}
