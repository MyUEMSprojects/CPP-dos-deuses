#include <iostream>
#include <string>
#include <utility> // Para std::move

// Classe que gerencia um recurso (simula um buffer dinâmico)
class Resource
{
private:
    std::string *data; // Ponteiro para um buffer de dados

public:
    // Construtor padrão
    Resource() : data(nullptr)
    {
        std::cout << "Construtor padrão.\n";
    }

    // Construtor parametrizado
    Resource(const std::string &value)
    {
        data = new std::string(value);
        std::cout << "Construtor parametrizado: " << *data << "\n";
    }

    // Construtor de cópia
    Resource(const Resource &other)
    {
        if (other.data)
        {
            data = new std::string(*other.data);
        }
        else
        {
            data = nullptr;
        }
        std::cout << "Construtor de cópia: " << (data ? *data : "null") << "\n";
    }

    // Operador de atribuição de cópia
    Resource &operator=(const Resource &other)
    {
        if (this != &other)
        {                 // Evitar auto-atribuição
            delete data; // Liberar recurso existente
            if (other.data)
            {
                data = new std::string(*other.data);
            }
            else
            {
                data = nullptr;
            }
        }
        std::cout << "Operador de atribuição de cópia: " << (data ? *data : "null") << "\n";
        return *this;
    }

    // Construtor de movimento
    Resource(Resource &&other) noexcept
    {
        data = other.data;   // "Rouba" o recurso do outro objeto
        other.data = nullptr; // Invalida o recurso do outro objeto
        std::cout << "Construtor de movimento: " << (data ? *data : "null") << "\n";
    }

    // Operador de atribuição de movimento
    Resource &operator=(Resource &&other) noexcept
    {
        if (this != &other)
        {                          // Evitar auto-atribuição
            delete data;          // Liberar recurso existente
            data = other.data;   // "Rouba" o recurso do outro objeto
            other.data = nullptr; // Invalida o recurso do outro objeto
        }
        std::cout << "Operador de atribuição de movimento: " << (data ? *data : "null") << "\n";
        return *this;
    }

    // Destrutor
    ~Resource()
    {
        // Importante: ler *data ANTES do delete. Fazer delete e só depois
        // dereferenciar o ponteiro (que continua com o mesmo endereço,
        // agora liberado) é use-after-free e é undefined behavior.
        std::cout << "Destrutor: " << (data ? *data : "null") << "\n";
        delete data;
    }

    // Método para exibir os dados
    void display() const
    {
        std::cout << "Dados: " << (data ? *data : "null") << "\n";
    }
};

int main()
{
    // 1. Semântica de movimento (std::move)
    Resource resource1("Hello, World!");
    Resource resource2 = std::move(resource1); // Construtor de movimento

    std::cout << "Resource1 após movimento:\n";
    resource1.display(); // Resource1 está vazio após o movimento

    std::cout << "Resource2 após movimento:\n";
    resource2.display(); // Resource2 agora possui os dados

    // 2. Construtores de movimento e operadores de atribuição de movimento
    Resource resource3("Move Assignment");
    Resource resource4;
    resource4 = std::move(resource3); // Operador de atribuição de movimento

    std::cout << "Resource3 após movimento:\n";
    resource3.display(); // Resource3 está vazio após o movimento

    std::cout << "Resource4 após movimento:\n";
    resource4.display(); // Resource4 agora possui os dados

    // 3. Rvalue references
    Resource &&rvalueRef = Resource("Rvalue Reference");
    std::cout << "Rvalue reference:\n";
    rvalueRef.display();

    return 0;
}
