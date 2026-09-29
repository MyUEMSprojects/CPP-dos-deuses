#include <iostream>
#include <memory>
#include <vector>
#include <numbers> // std::numbers::pi (C++20)

/*
. Polimorfismo com classes abstratas

    Crie uma hierarquia Shape (abstrata) com Circle e Rectangle, cada uma
    implementando area() e perimeter(). Armazene várias formas em um único
    std::vector<std::unique_ptr<Shape>> e some a área total percorrendo o
    vetor por ponteiro para a classe base — sem nenhum if/switch checando o
    tipo concreto.
*/

class Shape
{
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void describe() const
    {
        std::cout << "Área: " << area() << ", Perímetro: " << perimeter() << "\n";
    }
};

class Circle : public Shape
{
public:
    explicit Circle(double radius) : radius_(radius) {}

    double area() const override
    {
        return std::numbers::pi * radius_ * radius_;
    }

    double perimeter() const override
    {
        return 2 * std::numbers::pi * radius_;
    }

private:
    double radius_;
};

class Rectangle : public Shape
{
public:
    Rectangle(double width, double height) : width_(width), height_(height) {}

    double area() const override
    {
        return width_ * height_;
    }

    double perimeter() const override
    {
        return 2 * (width_ + height_);
    }

private:
    double width_;
    double height_;
};

int main()
{
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(3.0));
    shapes.push_back(std::make_unique<Rectangle>(4.0, 5.0));
    shapes.push_back(std::make_unique<Circle>(1.5));

    double totalArea = 0.0;
    for (const auto &shape : shapes)
    {
        shape->describe(); // dispatch polimórfico: cada forma sabe se descrever
        totalArea += shape->area();
    }

    std::cout << "Área total: " << totalArea << "\n";

    return 0;
}
