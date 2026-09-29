#include <iostream>
#include <vector>
#include <stdexcept>

/*
. Template de classe: pilha genérica

    Implemente uma classe template Stack<T> com:
      - push(valor): empilha um valor.
      - pop(): desempilha e retorna o valor do topo.
      - top(): consulta o valor do topo sem remover.
      - empty(): indica se a pilha está vazia.
      - size(): quantidade de elementos.

    pop() e top() devem lançar std::out_of_range se a pilha estiver vazia.
*/

template <typename T>
class Stack
{
public:
    void push(const T &value)
    {
        data_.push_back(value);
    }

    T pop()
    {
        if (empty())
        {
            throw std::out_of_range("Stack::pop chamado em pilha vazia");
        }
        T value = data_.back();
        data_.pop_back();
        return value;
    }

    const T &top() const
    {
        if (empty())
        {
            throw std::out_of_range("Stack::top chamado em pilha vazia");
        }
        return data_.back();
    }

    bool empty() const
    {
        return data_.empty();
    }

    std::size_t size() const
    {
        return data_.size();
    }

private:
    std::vector<T> data_;
};

int main()
{
    Stack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    std::cout << "Topo: " << intStack.top() << ", tamanho: " << intStack.size() << "\n";

    while (!intStack.empty())
    {
        std::cout << "Desempilhando: " << intStack.pop() << "\n";
    }

    // Funciona para qualquer tipo, inclusive std::string
    Stack<std::string> wordStack;
    wordStack.push("mundo");
    wordStack.push("olá");
    std::cout << wordStack.pop() << ", " << wordStack.pop() << "!\n";

    try
    {
        intStack.pop(); // pilha já vazia -> deve lançar exceção
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Erro esperado: " << e.what() << "\n";
    }

    return 0;
}
