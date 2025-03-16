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

class MinhaClasse
{
public:
    MinhaClasse(const std::string &nome) : nome_(nome) {}

    void exibir_nome() const
    {
        std::cout << "Nome: " << nome_ << "\n";
    }

private:
    std::string nome_;
};

void funcao_exemplo(int parametro)
{
    if (parametro > 0)
    {
        std::cout << "Parâmetro positivo: " << parametro << "\n";
    }
    else
    {
        std::cout << "Parâmetro não positivo.\n";
    }
}

int main()
{
    // Exemplo de código seguindo o Google C++ Style Guide
    MinhaClasse objeto("Exemplo");
    objeto.exibir_nome();

    int valor = 42;
    funcao_exemplo(valor);

    // 2. Ferramentas de formatação (clang-format)
    // O código abaixo está desformatado intencionalmente.
    // Use clang-format para formatá-lo automaticamente.
    std::vector<int> numeros = {1, 2, 3, 4, 5};
    for (const auto &num : numeros)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}