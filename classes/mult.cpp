#include <iostream>

class Veiculo
{
public:
    void mover()
    {
        std::cout << "Veiculo está se movendo.\n";
    }
};

class Aquatico
{
public:
    void nadar()
    {
        std::cout << "Aquatico está nadando.\n";
    }
};

class Terrestre
{
public:
    void andar()
    {
        std::cout << "Terrestre está andando.\n";
    }
};

// Herança múltipla
class Anfibio : public Aquatico, public Terrestre
{
public:
    void mostrarHabilidades()
    {
        nadar();
        andar();
    }
};

int main()
{
    Anfibio anfibio;
    anfibio.mostrarHabilidades();
    return 0;
}