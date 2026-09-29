#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <string>

// Ranges (C++20): permitem compor operações sobre sequências (filter,
// transform, take, ...) sem criar containers intermediários, usando o
// operador `|` como um pipeline — parecido com um "generator" preguiçoso.

int main()
{
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // 1. views::filter + views::transform compostos com '|'
    // Pega os números pares, eleva ao quadrado — tudo "lazy" (só é
    // avaliado quando o range é percorrido, sem alocar vetores intermediários).
    auto evenSquares = numbers
                        | std::views::filter([](int n)
                                              { return n % 2 == 0; })
                        | std::views::transform([](int n)
                                                 { return n * n; });

    std::cout << "Quadrados dos pares: ";
    for (int n : evenSquares)
    {
        std::cout << n << " ";
    }
    std::cout << "\n";

    // 2. views::take e views::drop: fatias preguiçosas da sequência
    std::cout << "3 primeiros: ";
    for (int n : numbers | std::views::take(3))
    {
        std::cout << n << " ";
    }
    std::cout << "\n";

    std::cout << "Todos exceto os 3 primeiros: ";
    for (int n : numbers | std::views::drop(3))
    {
        std::cout << n << " ";
    }
    std::cout << "\n";

    // 3. views::reverse
    std::cout << "Ordem reversa: ";
    for (int n : numbers | std::views::reverse)
    {
        std::cout << n << " ";
    }
    std::cout << "\n";

    // 4. std::ranges::sort e std::ranges::find: versões dos algoritmos
    // clássicos que recebem o range inteiro (sem begin()/end() manuais)
    std::vector<int> unsorted = {5, 3, 1, 4, 2};
    std::ranges::sort(unsorted);
    std::cout << "Ordenado com ranges::sort: ";
    for (int n : unsorted)
    {
        std::cout << n << " ";
    }
    std::cout << "\n";

    auto found = std::ranges::find(unsorted, 4);
    if (found != unsorted.end())
    {
        std::cout << "Encontrou 4 com ranges::find.\n";
    }

    // 5. Pipeline mais longo, várias views encadeadas
    std::vector<std::string> words = {"c++20", "concepts", "ranges", "coroutines", "stl"};
    auto longWordsUppercase = words
                               | std::views::filter([](const std::string &w)
                                                     { return w.size() > 5; })
                               | std::views::transform([](const std::string &w)
                                                        {
                                                            std::string upper = w;
                                                            std::ranges::transform(upper, upper.begin(), ::toupper);
                                                            return upper;
                                                        });

    std::cout << "Palavras com mais de 5 letras, em maiúsculas: ";
    for (const auto &w : longWordsUppercase)
    {
        std::cout << w << " ";
    }
    std::cout << "\n";

    return 0;
}
