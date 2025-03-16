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
    std::cin >> N;

    int *vec = new int[N];

    for (size_t i = 0; i < N - 1; i++)
    {
        vec[i] = i + 1;
    }

    for (size_t i = 0; i < N - 1; i++)
    {
        std::cout << vec[i] << '\n';
    }

    return 0;
}