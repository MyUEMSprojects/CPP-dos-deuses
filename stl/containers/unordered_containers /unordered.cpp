#include <iostream>
#include <unordered_set>
#include <unordered_map>

int main()
{
    // Exemplo de std::unordered_set
    std::cout << "=== std::unordered_set ===\n";
    std::unordered_set<int> conjunto = {5, 2, 8, 2, 5}; // Elementos duplicados são ignorados

    std::cout << "Elementos do unordered_set: ";
    for (int num : conjunto)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // Inserindo elementos
    conjunto.insert(10);
    conjunto.insert(3);

    std::cout << "Após inserir 10 e 3: ";
    for (int num : conjunto)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // Verificando se um elemento existe
    if (conjunto.find(8) != conjunto.end())
    {
        std::cout << "8 está no unordered_set!\n";
    }

    // Removendo um elemento
    conjunto.erase(5);
    std::cout << "Após remover 5: ";
    for (int num : conjunto)
    {
        std::cout << num << " ";
    }
    std::cout << "\n\n";

    // Exemplo de std::unordered_map
    std::cout << "=== std::unordered_map ===\n";
    std::unordered_map<std::string, int> idade;

    // Inserindo pares chave-valor
    idade["Alice"] = 25;
    idade["Bob"] = 30;
    idade["Charlie"] = 35;

    // Acessando valores por chave
    std::cout << "Idade de Alice: " << idade["Alice"] << "\n";

    // Iterando sobre o unordered_map
    std::cout << "Unordered_map completo:\n";
    for (const auto &par : idade)
    {
        std::cout << par.first << ": " << par.second << "\n";
    }

    // Verificando se uma chave existe
    if (idade.find("Bob") != idade.end())
    {
        std::cout << "Bob está no unordered_map!\n";
    }

    // Removendo uma chave
    idade.erase("Alice");
    std::cout << "Após remover Alice:\n";
    for (const auto &par : idade)
    {
        std::cout << par.first << ": " << par.second << "\n";
    }
    std::cout << "\n";

    // Exemplo de std::unordered_multiset
    std::cout << "=== std::unordered_multiset ===\n";
    std::unordered_multiset<int> multiconjunto = {5, 2, 8, 2, 5}; // Permite elementos duplicados

    std::cout << "Elementos do unordered_multiset: ";
    for (int num : multiconjunto)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // Inserindo elementos
    multiconjunto.insert(10);
    multiconjunto.insert(3);

    std::cout << "Após inserir 10 e 3: ";
    for (int num : multiconjunto)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // Verificando quantas vezes um elemento aparece
    std::cout << "Número de ocorrências de 2: " << multiconjunto.count(2) << "\n";

    // Removendo um elemento
    multiconjunto.erase(5);
    std::cout << "Após remover 5: ";
    for (int num : multiconjunto)
    {
        std::cout << num << " ";
    }
    std::cout << "\n\n";

    // Exemplo de std::unordered_multimap
    std::cout << "=== std::unordered_multimap ===\n";
    std::unordered_multimap<std::string, int> multimapa;

    // Inserindo pares chave-valor (permite chaves duplicadas)
    multimapa.insert({"Alice", 25});
    multimapa.insert({"Bob", 30});
    multimapa.insert({"Alice", 35}); // Chave duplicada

    // Iterando sobre o unordered_multimap
    std::cout << "Unordered_multimap completo:\n";
    for (const auto &par : multimapa)
    {
        std::cout << par.first << ": " << par.second << "\n";
    }

    // Verificando quantos valores existem para uma chave
    std::cout << "Número de valores para Alice: " << multimapa.count("Alice") << "\n";

    // Removendo uma chave específica
    multimapa.erase("Alice");
    std::cout << "Após remover Alice:\n";
    for (const auto &par : multimapa)
    {
        std::cout << par.first << ": " << par.second << "\n";
    }

    return 0;
}