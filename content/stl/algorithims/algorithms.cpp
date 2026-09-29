#include <iostream>
#include <vector>
#include <algorithm> // Para algoritmos como std::sort, std::find, etc.
#include <numeric>   // Para std::accumulate

int main()
{
    // Criando um vetor de inteiros
    std::vector<int> numbers = {5, 2, 8, 1, 9, 3, 7, 4, 6};

    // 1. Ordenação: std::sort
    std::sort(numbers.begin(), numbers.end());
    std::cout << "Vetor ordenado: ";
    for (int num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // 2. Busca: std::find
    auto it = std::find(numbers.begin(), numbers.end(), 7);
    if (it != numbers.end())
    {
        std::cout << "Elemento 7 encontrado no vetor!\n";
    }
    else
    {
        std::cout << "Elemento 7 não encontrado.\n";
    }

    // 3. Busca binária: std::binary_search
    bool exists = std::binary_search(numbers.begin(), numbers.end(), 3);
    std::cout << "Elemento 3 existe no vetor? " << (exists ? "Sim" : "Não") << "\n";

    // 4. Transformação: std::transform
    std::vector<int> squares(numbers.size());
    std::transform(numbers.begin(), numbers.end(), squares.begin(), [](int x)
                   { return x * x; });
    std::cout << "Quadrados dos elementos: ";
    for (int num : squares)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // 5. Remoção: std::remove
    auto new_end = std::remove(numbers.begin(), numbers.end(), 8);
    numbers.erase(new_end, numbers.end()); // Remove os elementos "removidos"
    std::cout << "Vetor após remover o 8: ";
    for (int num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // 6. Cópia: std::copy
    std::vector<int> copy_vec(numbers.size());
    std::copy(numbers.begin(), numbers.end(), copy_vec.begin());
    std::cout << "Cópia do vetor: ";
    for (int num : copy_vec)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // 7. Contagem: std::count
    int occurrences = std::count(numbers.begin(), numbers.end(), 5);
    std::cout << "Número de ocorrências de 5: " << occurrences << "\n";

    // 8. Acumulação: std::accumulate
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << "Soma dos elementos: " << sum << "\n";

    // 9. Permutação: std::next_permutation
    std::next_permutation(numbers.begin(), numbers.end());
    std::cout << "Próxima permutação do vetor: ";
    for (int num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}
