#include <iostream>
#include <vector>
#include <concepts>
#include <numeric>

/*
. Templates restritos com C++20 concepts

    Escreva uma função template `average(container)` que calcule a média
    dos elementos de qualquer container (vector, array, ...), mas que só
    aceite containers de tipos numéricos (inteiros ou ponto flutuante).

    Use um `concept` (requires std::integral<T> || std::floating_point<T>)
    para restringir o tipo dos elementos em tempo de compilação, em vez de
    descobrir o erro só em runtime ou com uma mensagem de erro de template
    ilegível.
*/

template <typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

template <typename Container>
    requires Numeric<typename Container::value_type>
double average(const Container &container)
{
    if (container.empty())
    {
        return 0.0;
    }
    auto sum = std::accumulate(container.begin(), container.end(), 0.0);
    return sum / static_cast<double>(container.size());
}

int main()
{
    std::vector<int> ints = {1, 2, 3, 4, 5};
    std::vector<double> doubles = {1.5, 2.5, 3.0};

    std::cout << "Média de ints: " << average(ints) << "\n";
    std::cout << "Média de doubles: " << average(doubles) << "\n";

    // A linha abaixo não compilaria (e é o comportamento desejado):
    // std::vector<std::string> words = {"a", "b"};
    // average(words); // erro de compilação: std::string não satisfaz Numeric

    return 0;
}
