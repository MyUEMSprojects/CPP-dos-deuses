#include <iostream>

int main()
{
    int linhas, colunas;

    // Solicita ao usuário as dimensões da matriz
    std::cout << "Digite o número de linhas: ";
    std::cin >> linhas;
    std::cout << "Digite o número de colunas: ";
    std::cin >> colunas;

    // Alocação dinâmica da matriz
    int **matriz = new int *[linhas]; // Aloca um array de ponteiros para as linhas
    for (int i = 0; i < linhas; ++i)
    {
        matriz[i] = new int[colunas]; // Aloca um array de inteiros para cada linha
    }

    // Preenche a matriz com valores sequenciais
    int contador = 1;
    for (int i = 0; i < linhas; ++i)
    {
        for (int j = 0; j < colunas; ++j)
        {
            matriz[i][j] = contador++;
        }
    }

    // Imprime a matriz
    std::cout << "Matriz:\n";
    for (int i = 0; i < linhas; ++i)
    {
        for (int j = 0; j < colunas; ++j)
        {
            std::cout << matriz[i][j] << "\t";
        }
        std::cout << "\n";
    }

    // Liberação da memória alocada
    for (int i = 0; i < linhas; ++i)
    {
        delete[] matriz[i]; // Libera cada linha da matriz
    }
    delete[] matriz; // Libera o array de ponteiros

    std::cout << "Memória liberada. Fim do programa.\n";

    return 0;
}