#include <iostream>

/*
. Alocação Dinâmica de Memória

    Crie um programa que aloque dinamicamente um array de inteiros com tamanho fornecido pelo usuário.

    Preencha o array com valores sequenciais (1, 2, 3, ...).

    Imprima os valores do array.

    Libere a memória alocada corretamente.
*/

int main()
{
    int N = 0;
    std::cout << "Digite o tamanho do array: ";
    if (!(std::cin >> N) || N <= 0)
    {
        std::cerr << "Entrada inválida: informe um inteiro positivo.\n";
        return 1;
    }

    int *vec = new int[N];

    for (int i = 0; i < N; i++)
    {
        vec[i] = i + 1;
    }

    for (int i = 0; i < N; i++)
    {
        std::cout << vec[i] << '\n';
    }

    delete[] vec;

    return 0;
}