#include <iostream>
#include <memory>
#include <string>

/*
 Smart Pointers (std::unique_ptr)

    Crie uma classe Person com atributos name (string) e age (int).

    Use std::unique_ptr para gerenciar a alocação dinâmica de um objeto Person.

    Modifique o name e a age da pessoa e imprima os valores.

    Não se esqueça de que o std::unique_ptr libera a memória automaticamente.
*/

class Person
{
private:
    std::string name;
    int age;
public:
    Person(/* args */): name(""), age(0) {
        std::cout << "Objeto inicalizado!" << "\n";
    }

    ~Person() {
        std::cout << "Memoria de Person liberada!";
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
    std::unique_ptr<Person> personPtr = std::make_unique<Person>();
    personPtr->setName("Felipe");
    personPtr->setAge(22);

    std::cout << "Nome: " << personPtr->getName() << ", Idade: " << personPtr->getAge() << "\n";
    return 0;
}
