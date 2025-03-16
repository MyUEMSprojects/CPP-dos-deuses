#include <iostream>

class Animal
{
public:
    void comer()
    {
        std::cout << "Animal está comendo.\n";
    }
};

class Mamifero : virtual public Animal
{ // Herança virtual
public:
    void amamentar()
    {
        std::cout << "Mamifero está amamentando.\n";
    }
};

class Ave : virtual public Animal
{ // Herança virtual
public:
    void voar()
    {
        std::cout << "Ave está voando.\n";
    }
};

// Herança múltipla com herança virtual
class Morcego : public Mamifero, public Ave
{
public:
    void mostrarHabilidades()
    {
        amamentar();
        voar();
        comer(); // Agora não há ambiguidade
    }
};

int main()
{
    Morcego morcego;
    morcego.mostrarHabilidades();
    return 0;
}