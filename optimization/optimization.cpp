#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

// 1. Análise de complexidade algorítmica (Big-O)
// Exemplo: Algoritmo de busca linear (O(n))
int busca_linear(const std::vector<int> &vetor, int valor)
{
    for (size_t i = 0; i < vetor.size(); ++i)
    {
        if (vetor[i] == valor)
        {
            return i; // Retorna o índice do valor encontrado
        }
    }
    return -1; // Valor não encontrado
}

// Exemplo: Algoritmo de busca binária (O(log n))
int busca_binaria(const std::vector<int> &vetor, int valor)
{
    int esquerda = 0;
    int direita = vetor.size() - 1;

    while (esquerda <= direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;

        if (vetor[meio] == valor)
        {
            return meio; // Retorna o índice do valor encontrado
        }

        if (vetor[meio] < valor)
        {
            esquerda = meio + 1;
        }
        else
        {
            direita = meio - 1;
        }
    }

    return -1; // Valor não encontrado
}

// 2. Técnicas de otimização de código
// Exemplo: Evitar cópias desnecessárias usando referências
void processar_vetor(const std::vector<int> &vetor)
{
    for (const auto &elemento : vetor)
    {
        std::cout << elemento << " ";
    }
    std::cout << "\n";
}

// Exemplo: Usar move semantics para evitar cópias
std::vector<int> criar_vetor_grande()
{
    std::vector<int> vetor(1000000, 42); // Vetor grande
    return vetor;                        // Move semantics é aplicado automaticamente
}

// 3. Uso de profilers para identificar gargalos
// Exemplo: Função ineficiente para demonstrar gargalos
void funcao_ineficiente()
{
    std::vector<int> vetor(1000000);

    // Preenche o vetor com valores
    for (int i = 0; i < 1000000; ++i)
    {
        vetor[i] = i;
    }

    // Ordena o vetor (O(n log n))
    std::sort(vetor.begin(), vetor.end());

    // Busca um valor (O(log n))
    int indice = busca_binaria(vetor, 500000);
    std::cout << "Índice encontrado: " << indice << "\n";
}

int main()
{
    // 1. Análise de complexidade algorítmica (Big-O)
    std::vector<int> vetor = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int valor = 6;
    int indice_linear = busca_linear(vetor, valor);
    std::cout << "Busca linear: Índice de " << valor << " é " << indice_linear << "\n";

    int indice_binaria = busca_binaria(vetor, valor);
    std::cout << "Busca binária: Índice de " << valor << " é " << indice_binaria << "\n";

    // 2. Técnicas de otimização de código
    processar_vetor(vetor);

    auto vetor_grande = criar_vetor_grande();
    std::cout << "Tamanho do vetor grande: " << vetor_grande.size() << "\n";

    // 3. Uso de profilers para identificar gargalos
    auto inicio = std::chrono::high_resolution_clock::now();
    funcao_ineficiente();
    auto fim = std::chrono::high_resolution_clock::now();

    auto duracao = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);
    std::cout << "Tempo de execução da função ineficiente: " << duracao.count() << " ms\n";

    return 0;
}