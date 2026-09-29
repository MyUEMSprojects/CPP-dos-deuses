#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <forward_list>
#include <algorithm>

template <typename Container>
void imprimir(const std::string &nome, const Container &c)
{
    std::cout << nome << ": ";
    for (const auto &item : c)
    {
        std::cout << item << " ";
    }
    std::cout << "\n";
}

int main()
{
    // std::vector: array dinâmico, acesso aleatório O(1), inserção no
    // fim amortizada O(1), inserção no meio/início O(n).
    std::vector<int> vetor = {5, 2, 9, 1, 5, 6};
    vetor.push_back(10);
    std::sort(vetor.begin(), vetor.end());
    imprimir("vector (ordenado)", vetor);

    // std::list: lista duplamente encadeada, inserção/remoção O(1) em
    // qualquer posição (com iterador), sem acesso aleatório.
    std::list<int> lista = {5, 2, 9, 1, 5, 6};
    lista.push_front(0);
    lista.remove(5); // remove todas as ocorrências de 5
    imprimir("list (após push_front(0) e remove(5))", lista);

    // std::deque: fila dupla, inserção/remoção O(1) nas duas pontas,
    // acesso aleatório O(1).
    std::deque<int> fila = {5, 2, 9, 1, 5, 6};
    fila.push_front(-1);
    fila.push_back(100);
    imprimir("deque (após push_front/push_back)", fila);

    // std::array: array de tamanho fixo conhecido em tempo de
    // compilação, sem overhead de alocação dinâmica.
    std::array<int, 5> arranjo = {5, 2, 9, 1, 5};
    std::sort(arranjo.begin(), arranjo.end());
    imprimir("array (ordenado)", arranjo);
    std::cout << "array.size() = " << arranjo.size() << "\n";

    // std::forward_list: lista simplesmente encadeada, mais leve que
    // list, apenas iteração para frente.
    std::forward_list<int> encadeada = {5, 2, 9};
    encadeada.push_front(1);
    imprimir("forward_list (após push_front(1))", encadeada);

    return 0;
}
