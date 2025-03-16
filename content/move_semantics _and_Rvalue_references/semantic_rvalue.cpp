#include <iostream>
#include <string>
#include <utility> // Para std::move

// Classe que gerencia um recurso (simula um buffer dinâmico)
class Recurso
{
private:
    std::string *dados; // Ponteiro para um buffer de dados

public:
    // Construtor padrão
    Recurso() : dados(nullptr)
    {
        std::cout << "Construtor padrão.\n";
    }

    // Construtor parametrizado
    Recurso(const std::string &valor)
    {
        dados = new std::string(valor);
        std::cout << "Construtor parametrizado: " << *dados << "\n";
    }

    // Construtor de cópia
    Recurso(const Recurso &outro)
    {
        if (outro.dados)
        {
            dados = new std::string(*outro.dados);
        }
        else
        {
            dados = nullptr;
        }
        std::cout << "Construtor de cópia: " << (dados ? *dados : "null") << "\n";
    }

    // Operador de atribuição de cópia
    Recurso &operator=(const Recurso &outro)
    {
        if (this != &outro)
        {                 // Evitar auto-atribuição
            delete dados; // Liberar recurso existente
            if (outro.dados)
            {
                dados = new std::string(*outro.dados);
            }
            else
            {
                dados = nullptr;
            }
        }
        std::cout << "Operador de atribuição de cópia: " << (dados ? *dados : "null") << "\n";
        return *this;
    }

    // Construtor de movimento
    Recurso(Recurso &&outro) noexcept
    {
        dados = outro.dados;   // "Rouba" o recurso do outro objeto
        outro.dados = nullptr; // Invalida o recurso do outro objeto
        std::cout << "Construtor de movimento: " << (dados ? *dados : "null") << "\n";
    }

    // Operador de atribuição de movimento
    Recurso &operator=(Recurso &&outro) noexcept
    {
        if (this != &outro)
        {                          // Evitar auto-atribuição
            delete dados;          // Liberar recurso existente
            dados = outro.dados;   // "Rouba" o recurso do outro objeto
            outro.dados = nullptr; // Invalida o recurso do outro objeto
        }
        std::cout << "Operador de atribuição de movimento: " << (dados ? *dados : "null") << "\n";
        return *this;
    }

    // Destrutor
    ~Recurso()
    {
        delete dados;
        std::cout << "Destrutor: " << (dados ? *dados : "null") << "\n";
    }

    // Método para exibir os dados
    void exibir() const
    {
        std::cout << "Dados: " << (dados ? *dados : "null") << "\n";
    }
};

int main()
{
    // 1. Semântica de movimento (std::move)
    Recurso recurso1("Hello, World!");
    Recurso recurso2 = std::move(recurso1); // Construtor de movimento

    std::cout << "Recurso1 após movimento:\n";
    recurso1.exibir(); // Recurso1 está vazio após o movimento

    std::cout << "Recurso2 após movimento:\n";
    recurso2.exibir(); // Recurso2 agora possui os dados

    // 2. Construtores de movimento e operadores de atribuição de movimento
    Recurso recurso3("Move Assignment");
    Recurso recurso4;
    recurso4 = std::move(recurso3); // Operador de atribuição de movimento

    std::cout << "Recurso3 após movimento:\n";
    recurso3.exibir(); // Recurso3 está vazio após o movimento

    std::cout << "Recurso4 após movimento:\n";
    recurso4.exibir(); // Recurso4 agora possui os dados

    // 3. Rvalue references
    Recurso &&rvalueRef = Recurso("Rvalue Reference");
    std::cout << "Rvalue reference:\n";
    rvalueRef.exibir();

    return 0;
}