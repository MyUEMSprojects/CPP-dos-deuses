#include <iostream>

class Animal
{
public:
    void eat()
    {
        std::cout << "Animal está comendo.\n";
    }
};

class Mammal : virtual public Animal
{ // Herança virtual
public:
    void nurse()
    {
        std::cout << "Mamifero está amamentando.\n";
    }
};

class Bird : virtual public Animal
{ // Herança virtual
public:
    void fly()
    {
        std::cout << "Ave está voando.\n";
    }
};

// Herança múltipla com herança virtual
class Bat : public Mammal, public Bird
{
public:
    void showAbilities()
    {
        nurse();
        fly();
        eat(); // Agora não há ambiguidade
    }
};

int main()
{
    Bat bat;
    bat.showAbilities();
    return 0;
}
