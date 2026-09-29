#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

/*
. Contagem de frequência de palavras

    Dado um vetor de palavras, conte quantas vezes cada uma aparece
    (usando std::unordered_map) e depois imprima o resultado ordenado da
    mais frequente para a menos frequente (copiando para um vector de
    pares e ordenando com std::sort + lambda).
*/

int main()
{
    std::vector<std::string> words = {
        "c++", "templates", "c++", "stl", "c++", "templates", "raii"};

    std::unordered_map<std::string, int> frequency;
    for (const auto &word : words)
    {
        ++frequency[word];
    }

    std::vector<std::pair<std::string, int>> ranked(frequency.begin(), frequency.end());
    std::sort(ranked.begin(), ranked.end(), [](const auto &a, const auto &b)
              {
                  if (a.second != b.second)
                  {
                      return a.second > b.second; // maior frequência primeiro
                  }
                  return a.first < b.first; // desempate alfabético
              });

    std::cout << "Frequência de palavras:\n";
    for (const auto &[word, count] : ranked)
    {
        std::cout << "  " << word << ": " << count << "\n";
    }

    return 0;
}
