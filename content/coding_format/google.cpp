#include <iostream>
#include <vector>
#include <string>

// 1. Estilo de código (Google C++ Style Guide)
// - Use 2 espaços para indentação.
// - Limite o comprimento das linhas a 80 caracteres.
// - Use snake_case para nomes de variáveis e funções.
// - Use CamelCase para nomes de classes.
// - Sempre inicialize variáveis.
// - Use `nullptr` em vez de `NULL` ou `0`.

class MyClass
{
public:
    MyClass(const std::string &name) : name_(name) {}

    void display_name() const
    {
        std::cout << "Nome: " << name_ << "\n";
    }

private:
    std::string name_;
};

void example_function(int parameter)
{
    if (parameter > 0)
    {
        std::cout << "Parâmetro positivo: " << parameter << "\n";
    }
    else
    {
        std::cout << "Parâmetro não positivo.\n";
    }
}

int main()
{
    // Exemplo de código seguindo o Google C++ Style Guide
    MyClass object("Exemplo");
    object.display_name();

    int value = 42;
    example_function(value);

    // 2. Ferramentas de formatação (clang-format)
    // O código abaixo está desformatado intencionalmente.
    // Use clang-format para formatá-lo automaticamente.
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    for (const auto &num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}
