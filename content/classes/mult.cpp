#include <iostream>

class Vehicle
{
public:
    void move()
    {
        std::cout << "Veiculo está se movendo.\n";
    }
};

class Aquatic
{
public:
    void swim()
    {
        std::cout << "Aquatico está nadando.\n";
    }
};

class Terrestrial
{
public:
    void walk()
    {
        std::cout << "Terrestre está andando.\n";
    }
};

// Herança múltipla
class Amphibian : public Aquatic, public Terrestrial
{
public:
    void showAbilities()
    {
        swim();
        walk();
    }
};

int main()
{
    Amphibian amphibian;
    amphibian.showAbilities();
    return 0;
}
