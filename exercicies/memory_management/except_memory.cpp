#include <iostream>
#include <memory>    // Para std::unique_ptr
#include <stdexcept> // Para std::invalid_argument

// Função que aloca dinamicamente um array de inteiros
std::unique_ptr<int[]> create_array(int size)
{
    if (size < 0)
    {
        throw std::invalid_argument("Tamanho do array não pode ser negativo.");
    }

    // Aloca dinamicamente um array de inteiros usando std::unique_ptr
    auto array = std::make_unique<int[]>(size);

    // Preenche o array com valores sequenciais
    for (int i = 0; i < size; ++i)
    {
        array[i] = i + 1;
    }

    return array; // Retorna o array (a propriedade é transferida)
}

int main()
{
    try
    {
        int size;

        // Solicita ao usuário o tamanho do array
        std::cout << "Digite o tamanho do array: ";
        std::cin >> size;

        // Chama a função para criar o array
        auto array = create_array(size);

        // Imprime os valores do array
        std::cout << "Array criado: ";
        for (int i = 0; i < size; ++i)
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
