#include <iostream>
#include <memory>
#include <string>

/*
. Smart Pointers (std::shared_ptr)

    Crie uma classe Car com atributos model (string) e year (int).

    Use std::shared_ptr para compartilhar a propriedade de um objeto Car entre duas funções.

    Imprima o número de referências ao std::shared_ptr antes e depois de compartilhá-lo.
*/

class Car
{
public:
    std::string model;
    int year;

    Car(const std::string &model, int year) : model(model), year(year)
    {
        std::cout << "Carro criado: " << model << " (" << year << ")\n";
    }

    ~Car()
    {
        std::cout << "Carro destruído: " << model << " (" << year << ")\n";
    }
};

void function1(std::shared_ptr<Car> car)
{
    std::cout << "Funcao1 - Modelo: " << car->model << ", Ano: " << car->year << "\n";
    std::cout << "Número de referências em funcao1: " << car.use_count() << "\n";
}

void function2(std::shared_ptr<Car> car)
{
    std::cout << "Funcao2 - Modelo: " << car->model << ", Ano: " << car->year << "\n";
    std::cout << "Número de referências em funcao2: " << car.use_count() << "\n";
}

int main()
{
    // Criando um shared_ptr para um objeto Car
    std::shared_ptr<Car> car = std::make_shared<Car>("Fusca", 1970);

    // Imprimindo o número de referências antes de compartilhar
    std::cout << "Número de referências após criação: " << car.use_count() << "\n";

    // Passando o shared_ptr para as funções
    function1(car);
    function2(car);

    // Imprimindo o número de referências após compartilhar
    std::cout << "Número de referências após compartilhamento: " << car.use_count() << "\n";

    // O shared_ptr será automaticamente destruído quando sair do escopo
    return 0;
}
