#include <iostream>
#include <string>

// 1. Definição de classes e objetos
class Car
{
private:
    // 2. Membros de classe (atributos e métodos)
    std::string brand;
    std::string model;
    int year;

public:
    // 3. Construtores e destrutores
    // Construtor padrão
    Car() : brand("Unknown"), model("Unknown"), year(0) {}

    // Construtor parametrizado
    Car(const std::string &brand, const std::string &model, int year)
        : brand(brand), model(model), year(year) {}

    // Destrutor virtual: obrigatório em classes base usadas
    // polimorficamente, para que delete via Car* destrua o objeto
    // derivado corretamente.
    virtual ~Car()
    {
        std::cout << "Destruindo o carro: " << brand << " " << model << "\n";
    }

    // Métodos públicos
    // 'virtual' é necessário para que SportsCar::showDetails()
    // seja chamado via ponteiro/referência para Car (polimorfismo real,
    // dispatch em tempo de execução). Sem isso seria apenas "hiding".
    virtual void showDetails() const
    {
        std::cout << "Marca: " << brand << ", Modelo: " << model << ", Ano: " << year << "\n";
    }

    // 4. Modificadores de acesso (getters e setters)
    void setBrand(const std::string &brand)
    {
        this->brand = brand;
    }

    std::string getBrand() const
    {
        return brand;
    }

    void setModel(const std::string &model)
    {
        this->model = model;
    }

    std::string getModel() const
    {
        return model;
    }

    void setYear(int year)
    {
        this->year = year;
    }

    int getYear() const
    {
        return year;
    }

    // 6. Função amiga (friend)
    friend void showPrivateInfo(const Car &car);
};

// 6. Função amiga (friend)
void showPrivateInfo(const Car &car)
{
    std::cout << "Informações privadas (friend): " << car.brand << " " << car.model << " " << car.year << "\n";
}

// 5. Encapsulamento, herança e polimorfismo
class SportsCar : public Car
{
private:
    int topSpeed;

public:
    // Construtor
    SportsCar(const std::string &brand, const std::string &model, int year, int topSpeed)
        : Car(brand, model, year), topSpeed(topSpeed) {}

    // Polimorfismo: Sobrescrevendo um método da classe base
    void showDetails() const override
    {
        Car::showDetails(); // Chama o método da classe base
        std::cout << "Velocidade Máxima: " << topSpeed << " km/h\n";
    }
};

int main()
{
    // 1. Definição de classes e objetos
    Car car1; // Usando o construtor padrão
    car1.setBrand("Toyota");
    car1.setModel("Corolla");
    car1.setYear(2020);

    Car car2("Ford", "Mustang", 1967); // Usando o construtor parametrizado

    // 2. Membros de classe (atributos e métodos)
    std::cout << "Detalhes do carro1:\n";
    car1.showDetails();

    std::cout << "Detalhes do carro2:\n";
    car2.showDetails();

    // 4. Modificadores de acesso (getters e setters)
    car1.setYear(2021);
    std::cout << "Novo ano do carro1: " << car1.getYear() << "\n";

    // 6. Função amiga (friend)
    showPrivateInfo(car2);

    // 5. Encapsulamento, herança e polimorfismo
    SportsCar sportsCar("Ferrari", "488 GTB", 2022, 330);
    std::cout << "Detalhes do carro esportivo:\n";
    sportsCar.showDetails();

    // Polimorfismo em tempo de execução: o método correto (o da classe
    // derivada) é escolhido mesmo acessando o objeto através de um
    // ponteiro para a classe base, graças a 'virtual' + 'override'.
    std::cout << "\nPolimorfismo via ponteiro para a classe base:\n";
    Car *basePointer = &sportsCar;
    basePointer->showDetails();

    return 0;
}
