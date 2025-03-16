#include <iostream>

class Animal
{
public:
    void comer()
    {
        std::cout << "Animal está comendo.\n";
    }
};

class Mamifero : public Animal
{
public:
    void amamentar()
    {
        std::cout << "Mamifero está amamentando.\n";
    }
};

class Ave : public Animal
{
public:
    void voar()
    {
        std::cout << "Ave está voando.\n";
    }
};

// Herança múltipla que causa o problema do diamante
class Morcego : public Mamifero, public Ave
{
public:
    void mostrarHabilidades()
    {
        amamentar();
        voar();
        // comer(); // Erro: Ambiguidade - qual comer() chamar?
    }
};

int main()
{
    Morcego morcego;
    morcego.mostrarHabilidades();
    return 0;
}