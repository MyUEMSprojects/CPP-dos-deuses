#include <iostream>
#include <unordered_set>
#include <unordered_map>

int main()
{
    // Exemplo de std::unordered_set
    std::cout << "=== std::unordered_set ===\n";
    std::unordered_set<int> numbers_set = {5, 2, 8, 2, 5}; // Elementos duplicados são ignorados

    std::cout << "Elementos do unordered_set: ";
    for (int num : numbers_set)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // Inserindo elementos
    numbers_set.insert(10);
    numbers_set.insert(3);

    std::cout << "Após inserir 10 e 3: ";
    for (int num : numbers_set)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // Verificando se um elemento existe
    if (numbers_set.find(8) != numbers_set.end())
    {
        std::cout << "8 está no unordered_set!\n";
    }

    // Removendo um elemento
    numbers_set.erase(5);
    std::cout << "Após remover 5: ";
    for (int num : numbers_set)
    {
        std::cout << num << " ";
    }
    std::cout << "\n\n";

    // Exemplo de std::unordered_map
    std::cout << "=== std::unordered_map ===\n";
    std::unordered_map<std::string, int> ages;

    // Inserindo pares chave-valor
    ages["Alice"] = 25;
    ages["Bob"] = 30;
    ages["Charlie"] = 35;

    // Acessando valores por chave
    std::cout << "Idade de Alice: " << ages["Alice"] << "\n";

    // Iterando sobre o unordered_map
    std::cout << "Unordered_map completo:\n";
    for (const auto &entry : ages)
    {
        std::cout << entry.first << ": " << entry.second << "\n";
    }

    // Verificando se uma chave existe
    if (ages.find("Bob") != ages.end())
    {
        std::cout << "Bob está no unordered_map!\n";
    }

    // Removendo uma chave
    ages.erase("Alice");
    std::cout << "Após remover Alice:\n";
    for (const auto &entry : ages)
    {
        std::cout << entry.first << ": " << entry.second << "\n";
    }
    std::cout << "\n";

    // Exemplo de std::unordered_multiset
    std::cout << "=== std::unordered_multiset ===\n";
    std::unordered_multiset<int> numbers_multiset = {5, 2, 8, 2, 5}; // Permite elementos duplicados

    std::cout << "Elementos do unordered_multiset: ";
    for (int num : numbers_multiset)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // Inserindo elementos
    numbers_multiset.insert(10);
    numbers_multiset.insert(3);

    std::cout << "Após inserir 10 e 3: ";
    for (int num : numbers_multiset)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // Verificando quantas vezes um elemento aparece
    std::cout << "Número de ocorrências de 2: " << numbers_multiset.count(2) << "\n";

    // Removendo um elemento
    numbers_multiset.erase(5);
    std::cout << "Após remover 5: ";
    for (int num : numbers_multiset)
    {
        std::cout << num << " ";
    }
    std::cout << "\n\n";

    // Exemplo de std::unordered_multimap
    std::cout << "=== std::unordered_multimap ===\n";
    std::unordered_multimap<std::string, int> ages_multimap;

    // Inserindo pares chave-valor (permite chaves duplicadas)
    ages_multimap.insert({"Alice", 25});
    ages_multimap.insert({"Bob", 30});
    ages_multimap.insert({"Alice", 35}); // Chave duplicada

    // Iterando sobre o unordered_multimap
    std::cout << "Unordered_multimap completo:\n";
    for (const auto &entry : ages_multimap)
    {
        std::cout << entry.first << ": " << entry.second << "\n";
    }

    // Verificando quantos valores existem para uma chave
    std::cout << "Número de valores para Alice: " << ages_multimap.count("Alice") << "\n";

    // Removendo uma chave específica
    ages_multimap.erase("Alice");
    std::cout << "Após remover Alice:\n";
    for (const auto &entry : ages_multimap)
    {
        std::cout << entry.first << ": " << entry.second << "\n";
    }

    return 0;
}
