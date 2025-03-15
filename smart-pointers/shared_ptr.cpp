#include <iostream>
#include <memory> // Para smart pointers

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
    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>();

    {
        // Criando outra referência para o mesmo objeto
        std::shared_ptr<MyClass> ptr2 = ptr1;

        std::cout << "Dentro do escopo interno:\n";
        ptr2->doSomething();
        std::cout << "Contagem de referências: " << ptr1.use_count() << "\n";
    }

    std::cout << "Fora do escopo interno:\n";
    ptr1->doSomething();
    std::cout << "Contagem de referências: " << ptr1.use_count() << "\n";

    // O objeto será destruído quando a última referência sair do escopo
    return 0;
}