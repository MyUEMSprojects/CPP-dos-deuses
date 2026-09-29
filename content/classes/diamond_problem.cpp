#include <iostream>

class Animal
{
public:
    void eat()
    {
        std::cout << "Animal está comendo.\n";
    }
};

class Mammal : public Animal
{
public:
    void nurse()
    {
        std::cout << "Mamifero está amamentando.\n";
    }
};

class Bird : public Animal
{
public:
    void fly()
    {
        std::cout << "Ave está voando.\n";
    }
};

// Herança múltipla que causa o problema do diamante
class Bat : public Mammal, public Bird
{
public:
    void showAbilities()
    {
        nurse();
        fly();
        // eat(); // Erro: Ambiguidade - qual eat() chamar?
    }
};

int main()
{
    Bat bat;
    bat.showAbilities();
    return 0;
}
