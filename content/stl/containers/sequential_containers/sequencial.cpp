#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <forward_list>
#include <algorithm>

template <typename Container>
void print(const std::string &name, const Container &c)
{
    std::cout << name << ": ";
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
    std::vector<int> vec = {5, 2, 9, 1, 5, 6};
    vec.push_back(10);
    std::sort(vec.begin(), vec.end());
    print("vector (ordenado)", vec);

    // std::list: lista duplamente encadeada, inserção/remoção O(1) em
    // qualquer posição (com iterador), sem acesso aleatório.
    std::list<int> linked_list = {5, 2, 9, 1, 5, 6};
    linked_list.push_front(0);
    linked_list.remove(5); // remove todas as ocorrências de 5
    print("list (após push_front(0) e remove(5))", linked_list);

    // std::deque: fila dupla, inserção/remoção O(1) nas duas pontas,
    // acesso aleatório O(1).
    std::deque<int> double_ended_queue = {5, 2, 9, 1, 5, 6};
    double_ended_queue.push_front(-1);
    double_ended_queue.push_back(100);
    print("deque (após push_front/push_back)", double_ended_queue);

    // std::array: array de tamanho fixo conhecido em tempo de
    // compilação, sem overhead de alocação dinâmica.
    std::array<int, 5> fixed_array = {5, 2, 9, 1, 5};
    std::sort(fixed_array.begin(), fixed_array.end());
    print("array (ordenado)", fixed_array);
    std::cout << "array.size() = " << fixed_array.size() << "\n";

    // std::forward_list: lista simplesmente encadeada, mais leve que
    // list, apenas iteração para frente.
    std::forward_list<int> forward_linked_list = {5, 2, 9};
    forward_linked_list.push_front(1);
    print("forward_list (após push_front(1))", forward_linked_list);

    return 0;
}
