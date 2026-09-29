#include <iostream>

int main()
{
    int rows, columns;

    // Solicita ao usuário as dimensões da matriz
    std::cout << "Digite o número de linhas: ";
    std::cin >> rows;
    std::cout << "Digite o número de colunas: ";
    std::cin >> columns;

    if (!std::cin || rows <= 0 || columns <= 0)
    {
        std::cerr << "Entrada inválida: linhas e colunas devem ser inteiros positivos.\n";
        return 1;
    }

    // Alocação dinâmica da matriz
    int **matrix = new int *[rows]; // Aloca um array de ponteiros para as linhas
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new int[columns]; // Aloca um array de inteiros para cada linha
    }

    // Preenche a matriz com valores sequenciais
    int counter = 1;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            matrix[i][j] = counter++;
        }
    }

    // Imprime a matriz
    std::cout << "Matriz:\n";
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }

    // Liberação da memória alocada
    for (int i = 0; i < rows; ++i)
    {
        delete[] matrix[i]; // Libera cada linha da matriz
    }
    delete[] matrix; // Libera o array de ponteiros

    std::cout << "Memória liberada. Fim do programa.\n";

    return 0;
}
