#include <iostream>
#include <string>
#include <cmath>

// 1. Sobrecarga de operadores para classes
class Vetor2D
{
private:
    double x, y;

public:
    // Construtor
    Vetor2D(double x = 0, double y = 0) : x(x), y(y) {}

    // Sobrecarga do operador de adição (binário)
    Vetor2D operator+(const Vetor2D &outro) const
    {
        return Vetor2D(x + outro.x, y + outro.y);
    }

    // Sobrecarga do operador de subtração (binário)
    Vetor2D operator-(const Vetor2D &outro) const
    {
        return Vetor2D(x - outro.x, y - outro.y);
    }

    // Sobrecarga do operador de multiplicação por escalar (binário)
    Vetor2D operator*(double escalar) const
    {
        return Vetor2D(x * escalar, y * escalar);
    }

    // Sobrecarga do operador de igualdade (binário)
    bool operator==(const Vetor2D &outro) const
    {
        return x == outro.x && y == outro.y;
    }

    // Sobrecarga do operador de negação (unário)
    Vetor2D operator-() const
    {
        return Vetor2D(-x, -y);
    }

    // Sobrecarga do operador de incremento (unário, pré-fixado)
    Vetor2D &operator++()
    {
        x++;
        y++;
        return *this;
    }

    // Sobrecarga do operador de incremento (unário, pós-fixado)
    Vetor2D operator++(int)
    {
        Vetor2D temp = *this;
        ++(*this);
        return temp;
    }

    // Sobrecarga do operador de conversão para double (conversão implícita)
    operator double() const
    {
        return std::sqrt(x * x + y * y); // Retorna a magnitude do vetor
    }

    // Sobrecarga do operador de inserção (<<) como função amiga
    friend std::ostream &operator<<(std::ostream &os, const Vetor2D &vetor);

    // Método para exibir o vetor
    void exibir() const
    {
        std::cout << "(" << x << ", " << y << ")\n";
    }
};

// Sobrecarga do operador de inserção (<<)
std::ostream &operator<<(std::ostream &os, const Vetor2D &vetor)
{
    os << "(" << vetor.x << ", " << vetor.y << ")";
    return os;
}

int main()
{
    // 1. Sobrecarga de operadores para classes
    Vetor2D v1(3, 4);
    Vetor2D v2(1, 2);

    // Operador de adição
    Vetor2D v3 = v1 + v2;
    std::cout << "v1 + v2 = " << v3 << "\n";

    // Operador de subtração
    Vetor2D v4 = v1 - v2;
    std::cout << "v1 - v2 = " << v4 << "\n";

    // Operador de multiplicação por escalar
    Vetor2D v5 = v1 * 2;
    std::cout << "v1 * 2 = " << v5 << "\n";

    // Operador de igualdade
    std::cout << "v1 == v2? " << (v1 == v2 ? "Sim" : "Não") << "\n";

    // Operador de negação (unário)
    Vetor2D v6 = -v1;
    std::cout << "-v1 = " << v6 << "\n";

    // Operador de incremento (pré-fixado)
    ++v1;
    std::cout << "++v1 = " << v1 << "\n";

    // Operador de incremento (pós-fixado)
    Vetor2D v7 = v2++;
    std::cout << "v2++ = " << v7 << "\n";
    std::cout << "v2 após incremento = " << v2 << "\n";

    // 3. Operadores de conversão
    double magnitude = static_cast<double>(v1); // Conversão explícita
    std::cout << "Magnitude de v1: " << magnitude << "\n";

    return 0;
}