#include <iostream>
#include <memory>

// Classe Bicicleta
class Bicicleta
{   
public:
    Bicicleta(const std::string &modelo) : modelo_(modelo)
    {
        std::cout << "Bicicleta " << modelo_ << " criada.\n";
    }

    ~Bicicleta()
    {
        std::cout << "Bicicleta " << modelo_ << " destruída.\n";
    }

    std::string get_modelo() const
    {
        return modelo_;
    }

private:
    std::string modelo_;
};

// Classe Ciclista
class Ciclista
{
public:
    Ciclista(const std::string &nome) : nome_(nome)
    {
        std::cout << "Ciclista " << nome_ << " criado.\n";
    }

    ~Ciclista()
    {
        std::cout << "Ciclista " << nome_ << " destruído.\n";
    }

    void atribuir_bicicleta(std::shared_ptr<Bicicleta> bicicleta)
    {
        bicicleta_ = bicicleta;
        std::cout << nome_ << " está usando a bicicleta " << bicicleta->get_modelo() << ".\n";
    }

    void usar_bicicleta()
    {
        if (auto bicicleta = bicicleta_.lock())
        {
            std::cout << nome_ << " está pedalando a bicicleta " << bicicleta->get_modelo() << ".\n";
        }
        else
        {
            std::cout << nome_ << " não tem uma bicicleta para pedalar.\n";
        }
    }

private:
    std::string nome_;
    std::weak_ptr<Bicicleta> bicicleta_; // Usa weak_ptr para evitar ciclos de referência
};

int main()
{
    // Cria uma bicicleta gerenciada por shared_ptr
    auto bicicleta = std::make_shared<Bicicleta>("Mountain Bike");

    {
        // Cria um ciclista
        Ciclista ciclista("João");

        // Atribui a bicicleta ao ciclista
        ciclista.atribuir_bicicleta(bicicleta);

        // Usa a bicicleta
        ciclista.usar_bicicleta();

        // O ciclista sai do escopo aqui
    }

    // A bicicleta ainda existe, pois o shared_ptr principal ainda a mantém viva
    std::cout << "Bicicleta ainda existe? " << (bicicleta ? "Sim" : "Não") << "\n";

    return 0;
}