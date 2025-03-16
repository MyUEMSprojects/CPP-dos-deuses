#include <iostream>
#include <vector>
#include <list>
#include <algorithm> // Para std::for_each, std::sort, etc.

int main()
{
    // Exemplo com std::vector
    std::vector<int> numeros = {5, 2, 8, 1, 9, 3};

    // 1. Iterando com iteradores clássicos
    std::cout << "Elementos do vetor: ";
    for (auto it = numeros.begin(); it != numeros.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // 2. Iterando com range-based for (usa iteradores internamente)
    std::cout << "Elementos do vetor (range-based for): ";
    for (int num : numeros)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // 3. Usando std::for_each com iteradores
    std::cout << "Elementos do vetor (std::for_each): ";
    std::for_each(numeros.begin(), numeros.end(), [](int num)
                  { std::cout << num << " "; });
    std::cout << "\n";

    // 4. Iteradores reversos
    std::cout << "Elementos do vetor em ordem reversa: ";
    for (auto it = numeros.rbegin(); it != numeros.rend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // 5. Usando std::next e std::prev
    auto it = numeros.begin();
    std::cout << "Primeiro elemento: " << *it << "\n";
    std::cout << "Segundo elemento: " << *std::next(it, 1) << "\n";
    std::cout << "Último elemento: " << *std::prev(numeros.end(), 1) << "\n";

    // 6. Usando std::advance
    auto it2 = numeros.begin();
    std::advance(it2, 3); // Avança 3 posições
    std::cout << "Elemento na posição 3: " << *it2 << "\n";

    // 7. Usando std::distance
    auto inicio = numeros.begin();
    auto fim = numeros.end();
    std::cout << "Distância entre início e fim: " << std::distance(inicio, fim) << "\n";

    // Exemplo com std::list
    std::list<int> lista = {10, 20, 30, 40, 50};

    // 8. Iterando com iteradores bidirecionais
    std::cout << "Elementos da lista: ";
    for (auto it = lista.begin(); it != lista.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // 9. Usando std::copy com iteradores
    std::vector<int> copia(lista.size());
    std::copy(lista.begin(), lista.end(), copia.begin());
    std::cout << "Cópia da lista para vetor: ";
    for (int num : copia)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}