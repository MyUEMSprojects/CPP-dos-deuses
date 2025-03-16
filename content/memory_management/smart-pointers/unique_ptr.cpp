#include <iostream>
#include <memory> // Para smart pointers

class MyClass {
public:
    MyClass() {
        std::cout << "MyClass criado!\n";
    }

    ~MyClass() {
        std::cout << "MyClass destruído!\n";
    }

    void doSomething() {
        std::cout << "Fazendo algo...\n";
    }
};

int main() {
    // Criando um unique_ptr
    std::unique_ptr<MyClass> ptr = std::make_unique<MyClass>();

    // Usando o objeto gerenciado pelo unique_ptr
    ptr->doSomething();

    // O unique_ptr será automaticamente destruído quando sair do escopo,
    // liberando a memória alocada.
    return 0;
}