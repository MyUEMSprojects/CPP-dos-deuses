#include <iostream>
#include <memory>    // Para std::unique_ptr
#include <stdexcept> // Para std::invalid_argument

// Função que aloca dinamicamente um array de inteiros
std::unique_ptr<int[]> criar_array(int tamanho)
{
    if (tamanho < 0)
    {
        throw std::invalid_argument("Tamanho do array não pode ser negativo.");
    }

    // Aloca dinamicamente um array de inteiros usando std::unique_ptr
    auto array = std::make_unique<int[]>(tamanho);

    // Preenche o array com valores sequenciais
    for (int i = 0; i < tamanho; ++i)
    {
        array[i] = i + 1;
    }

    return array; // Retorna o array (a propriedade é transferida)
}

int main()
{
    try
    {
        int tamanho;

        // Solicita ao usuário o tamanho do array
        std::cout << "Digite o tamanho do array: ";
        std::cin >> tamanho;

        // Chama a função para criar o array
        auto array = criar_array(tamanho);

        // Imprime os valores do array
        std::cout << "Array criado: ";
        for (int i = 0; i < tamanho; ++i)
        {
            std::cout << array[i] << " ";
        }
        std::cout << "\n";
    }
    catch (const std::invalid_argument &e)
    {
        // Captura a exceção lançada pela função
        std::cerr << "Erro: " << e.what() << "\n";
    }

    return 0;
}