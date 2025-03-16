#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <forward_list>

int main()
{
    std::vector<int> vector = {5, 2, 9, 1, 5, 6};
    std::list<int> lista = {5, 2, 9, 1, 5, 6};
    std::deque<int> deque = {5, 2, 9, 1, 5, 6};
    std::array<int, 5> array = {5, 2, 9, 1, 5};
    std::forward_list<int> numeros = {5, 2, 9};
    return 0;
}