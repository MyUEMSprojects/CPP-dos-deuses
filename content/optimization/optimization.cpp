#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

// 1. Análise de complexidade algorítmica (Big-O)
// Exemplo: Algoritmo de busca linear (O(n))
int linear_search(const std::vector<int> &values, int target)
{
    for (size_t i = 0; i < values.size(); ++i)
    {
        if (values[i] == target)
        {
            return i; // Retorna o índice do valor encontrado
        }
    }
    return -1; // Valor não encontrado
}

// Exemplo: Algoritmo de busca binária (O(log n))
int binary_search(const std::vector<int> &values, int target)
{
    int left = 0;
    int right = values.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (values[mid] == target)
        {
            return mid; // Retorna o índice do valor encontrado
        }

        if (values[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1; // Valor não encontrado
}

// 2. Técnicas de otimização de código
// Exemplo: Evitar cópias desnecessárias usando referências
void process_vector(const std::vector<int> &values)
{
    for (const auto &element : values)
    {
        std::cout << element << " ";
    }
    std::cout << "\n";
}

// Exemplo: Usar move semantics para evitar cópias
std::vector<int> create_large_vector()
{
    std::vector<int> values(1000000, 42); // Vetor grande
    return values;                        // Move semantics é aplicado automaticamente
}

// 3. Uso de profilers para identificar gargalos
// Exemplo: Função ineficiente para demonstrar gargalos
void inefficient_function()
{
    std::vector<int> values(1000000);

    // Preenche o vetor com valores
    for (int i = 0; i < 1000000; ++i)
    {
        values[i] = i;
    }

    // Ordena o vetor (O(n log n))
    std::sort(values.begin(), values.end());

    // Busca um valor (O(log n))
    int index = binary_search(values, 500000);
    std::cout << "Índice encontrado: " << index << "\n";
}

int main()
{
    // 1. Análise de complexidade algorítmica (Big-O)
    std::vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int target = 6;
    int linear_index = linear_search(values, target);
    std::cout << "Busca linear: Índice de " << target << " é " << linear_index << "\n";

    int binary_index = binary_search(values, target);
    std::cout << "Busca binária: Índice de " << target << " é " << binary_index << "\n";

    // 2. Técnicas de otimização de código
    process_vector(values);

    auto large_vector = create_large_vector();
    std::cout << "Tamanho do vetor grande: " << large_vector.size() << "\n";

    // 3. Uso de profilers para identificar gargalos
    auto start = std::chrono::high_resolution_clock::now();
    inefficient_function();
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Tempo de execução da função ineficiente: " << elapsed.count() << " ms\n";

    return 0;
}
