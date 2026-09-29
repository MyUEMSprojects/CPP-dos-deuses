#include <iostream>
#include <string>
#include <cmath>

// 1. Sobrecarga de operadores para classes
class Vector2D
{
private:
    double x, y;

public:
    // Construtor
    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}

    // Sobrecarga do operador de adição (binário)
    Vector2D operator+(const Vector2D &other) const
    {
        return Vector2D(x + other.x, y + other.y);
    }

    // Sobrecarga do operador de subtração (binário)
    Vector2D operator-(const Vector2D &other) const
    {
        return Vector2D(x - other.x, y - other.y);
    }

    // Sobrecarga do operador de multiplicação por escalar (binário)
    Vector2D operator*(double scalar) const
    {
        return Vector2D(x * scalar, y * scalar);
    }

    // Sobrecarga do operador de igualdade (binário)
    bool operator==(const Vector2D &other) const
    {
        return x == other.x && y == other.y;
    }

    // Sobrecarga do operador de negação (unário)
    Vector2D operator-() const
    {
        return Vector2D(-x, -y);
    }

    // Sobrecarga do operador de incremento (unário, pré-fixado)
    Vector2D &operator++()
    {
        x++;
        y++;
        return *this;
    }

    // Sobrecarga do operador de incremento (unário, pós-fixado)
    Vector2D operator++(int)
    {
        Vector2D temp = *this;
        ++(*this);
        return temp;
    }

    // Sobrecarga do operador de conversão para double (conversão explícita)
    // 'explicit' evita conversões implícitas indesejadas (ex.: ambiguidade
    // entre Vector2D::operator*(double) e o operator* embutido para double)
    explicit operator double() const
    {
        return std::sqrt(x * x + y * y); // Retorna a magnitude do vetor
    }

    // Sobrecarga do operador de inserção (<<) como função amiga
    friend std::ostream &operator<<(std::ostream &os, const Vector2D &vector);

    // Método para exibir o vetor
    void display() const
    {
        std::cout << "(" << x << ", " << y << ")\n";
    }
};

// Sobrecarga do operador de inserção (<<)
std::ostream &operator<<(std::ostream &os, const Vector2D &vector)
{
    os << "(" << vector.x << ", " << vector.y << ")";
    return os;
}

int main()
{
    // 1. Sobrecarga de operadores para classes
    Vector2D v1(3, 4);
    Vector2D v2(1, 2);

    // Operador de adição
    Vector2D v3 = v1 + v2;
    std::cout << "v1 + v2 = " << v3 << "\n";

    // Operador de subtração
    Vector2D v4 = v1 - v2;
    std::cout << "v1 - v2 = " << v4 << "\n";

    // Operador de multiplicação por escalar
    Vector2D v5 = v1 * 2;
    std::cout << "v1 * 2 = " << v5 << "\n";

    // Operador de igualdade
    std::cout << "v1 == v2? " << (v1 == v2 ? "Sim" : "Não") << "\n";

    // Operador de negação (unário)
    Vector2D v6 = -v1;
    std::cout << "-v1 = " << v6 << "\n";

    // Operador de incremento (pré-fixado)
    ++v1;
    std::cout << "++v1 = " << v1 << "\n";

    // Operador de incremento (pós-fixado)
    Vector2D v7 = v2++;
    std::cout << "v2++ = " << v7 << "\n";
    std::cout << "v2 após incremento = " << v2 << "\n";

    // 3. Operadores de conversão
    double magnitude = static_cast<double>(v1); // Conversão explícita
    std::cout << "Magnitude de v1: " << magnitude << "\n";

    return 0;
}
