#include <iostream>
#include <memory>
#include <string>

/*
 Smart Pointers (std::unique_ptr)

    Crie uma classe Pessoa com atributos nome (string) e idade (int).

    Use std::unique_ptr para gerenciar a alocação dinâmica de um objeto Pessoa.

    Modifique o nome e a idade da pessoa e imprima os valores.

    Não se esqueça de que o std::unique_ptr libera a memória automaticamente.
*/

class Pessoa
{
private:
    std::string name;
    int age;
public:
    Pessoa(/* args */): name(""), age(0) {
        std::cout << "Objeto inicalizado!" << "\n";
    }

    ~Pessoa() {
        std::cout << "Memoria de Pessoa liberada!";
    }

    void setName(std::string name) {
        this->name = name;
    }

    std::string getName() const {
        return this->name;
    }

    void setAge(int age) {
        this->age = age;
    }

    int getAge() const {
        return this->age;
    }
};


int main()
{
    std::unique_ptr<Pessoa> pessoaPtr = std::make_unique<Pessoa>();
    pessoaPtr->setName("Felipe");
    pessoaPtr->setAge(22);

    std::cout << "Nome: " << pessoaPtr->getName() << ", Idade: " << pessoaPtr->getAge() << "\n";
    return 0;
}