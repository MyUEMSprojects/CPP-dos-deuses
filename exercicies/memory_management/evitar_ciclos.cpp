#include <iostream>
#include <memory>

// Classe Bicycle
class Bicycle
{
public:
    Bicycle(const std::string &model) : model_(model)
    {
        std::cout << "Bicicleta " << model_ << " criada.\n";
    }

    ~Bicycle()
    {
        std::cout << "Bicicleta " << model_ << " destruída.\n";
    }

    std::string get_model() const
    {
        return model_;
    }

private:
    std::string model_;
};

// Classe Cyclist
class Cyclist
{
public:
    Cyclist(const std::string &name) : name_(name)
    {
        std::cout << "Ciclista " << name_ << " criado.\n";
    }

    ~Cyclist()
    {
        std::cout << "Ciclista " << name_ << " destruído.\n";
    }

    void assign_bicycle(std::shared_ptr<Bicycle> bicycle)
    {
        bicycle_ = bicycle;
        std::cout << name_ << " está usando a bicicleta " << bicycle->get_model() << ".\n";
    }

    void ride_bicycle()
    {
        if (auto bicycle = bicycle_.lock())
        {
            std::cout << name_ << " está pedalando a bicicleta " << bicycle->get_model() << ".\n";
        }
        else
        {
            std::cout << name_ << " não tem uma bicicleta para pedalar.\n";
        }
    }

private:
    std::string name_;
    std::weak_ptr<Bicycle> bicycle_; // Usa weak_ptr para evitar ciclos de referência
};

int main()
{
    // Cria uma bicicleta gerenciada por shared_ptr
    auto bicycle = std::make_shared<Bicycle>("Mountain Bike");

    {
        // Cria um ciclista
        Cyclist cyclist("João");

        // Atribui a bicicleta ao ciclista
        cyclist.assign_bicycle(bicycle);

        // Usa a bicicleta
        cyclist.ride_bicycle();

        // O ciclista sai do escopo aqui
    }

    // A bicicleta ainda existe, pois o shared_ptr principal ainda a mantém viva
    std::cout << "Bicicleta ainda existe? " << (bicycle ? "Sim" : "Não") << "\n";

    return 0;
}
