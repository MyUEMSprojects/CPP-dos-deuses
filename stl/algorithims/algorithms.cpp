#include <iostream>
#include <vector>
#include <algorithm> // Para algoritmos como std::sort, std::find, etc.
#include <numeric>   // Para std::accumulate

int main()
{
    // Criando um vetor de inteiros
    std::vector<int> numeros = {5, 2, 8, 1, 9, 3, 7, 4, 6};

    // 1. Ordenação: std::sort
    std::sort(numeros.begin(), numeros.end());
    std::cout << "Vetor ordenado: ";
    for (int num : numeros)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // 2. Busca: std::find
    auto it = std::find(numeros.begin(), numeros.end(), 7);
    if (it != numeros.end())
    {
        std::cout << "Elemento 7 encontrado no vetor!\n";
    }
    else
    {
        std::cout << "Elemento 7 não encontrado.\n";
    }

    // 3. Busca binária: std::binary_search
    bool existe = std::binary_search(numeros.begin(), numeros.end(), 3);
    std::cout << "Elemento 3 existe no vetor? " << (existe ? "Sim" : "Não") << "\n";

    // 4. Transformação: std::transform
    std::vector<int> quadrados(numeros.size());
    std::transform(numeros.begin(), numeros.end(), quadrados.begin(), [](int x)
                   { return x * x; });
    std::cout << "Quadrados dos elementos: ";
    for (int num : quadrados)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // 5. Remoção: std::remove
    auto novo_fim = std::remove(numeros.begin(), numeros.end(), 8);
    numeros.erase(novo_fim, numeros.end()); // Remove os elementos "removidos"
    std::cout << "Vetor após remover o 8: ";
    for (int num : numeros)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // 6. Cópia: std::copy
    std::vector<int> copia(numeros.size());
    std::copy(numeros.begin(), numeros.end(), copia.begin());
    std::cout << "Cópia do vetor: ";
    for (int num : copia)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // 7. Contagem: std::count
    int quantidade = std::count(numeros.begin(), numeros.end(), 5);
    std::cout << "Número de ocorrências de 5: " << quantidade << "\n";

    // 8. Acumulação: std::accumulate
    int soma = std::accumulate(numeros.begin(), numeros.end(), 0);
    std::cout << "Soma dos elementos: " << soma << "\n";

    // 9. Permutação: std::next_permutation
    std::next_permutation(numeros.begin(), numeros.end());
    std::cout << "Próxima permutação do vetor: ";
    for (int num : numeros)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}