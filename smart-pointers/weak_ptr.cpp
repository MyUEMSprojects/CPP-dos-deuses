#include <iostream>
#include <memory>

class MyClass
{
public:
    MyClass()
    {
        std::cout << "MyClass criado!\n";
    }

    ~MyClass()
    {
        std::cout << "MyClass destruído!\n";
    }

    void doSomething()
    {
        std::cout << "Fazendo algo...\n";
    }
};

int main()
{
    // Criando um shared_ptr
    std::shared_ptr<MyClass> sharedPtr = std::make_shared<MyClass>();

    // Criando um weak_ptr a partir do shared_ptr
    std::weak_ptr<MyClass> weakPtr = sharedPtr;

    // Verificando se o objeto ainda existe
    if (auto tempPtr = weakPtr.lock())
    {
        std::cout << "Objeto ainda existe. Fazendo algo...\n";
        tempPtr->doSomething();
    }
    else
    {
        std::cout << "Objeto já foi destruído.\n";
    }

    // Resetando o shared_ptr (destruindo o objeto)
    sharedPtr.reset();

    // Verificando novamente
    if (auto tempPtr = weakPtr.lock())
    {
        std::cout << "Objeto ainda existe.\n";
    }
    else
    {
        std::cout << "Objeto já foi destruído.\n";
    }

    return 0;
}