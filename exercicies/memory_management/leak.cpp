#include <iostream>

int main()
{
    // Alocação dinâmica de um array de inteiros
    int *array = new int[100]; // Aloca memória para 100 inteiros

    // Preenche o array com valores
    for (int i = 0; i < 100; ++i)
    {
        array[i] = i;
    }

    // Imprime alguns valores do array
    std::cout << "Array[0]: " << array[0] << "\n";
    std::cout << "Array[99]: " << array[99] << "\n";

    // Esquece de liberar a memória alocada
    // delete[] array; // Comentei essa linha para simular o vazamento

    return 0;
}