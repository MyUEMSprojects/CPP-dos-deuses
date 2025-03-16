#include <iostream>
#include <memory>
#include <string>

/*
. Smart Pointers (std::shared_ptr)

    Crie uma classe Carro com atributos modelo (string) e ano (int).

    Use std::shared_ptr para compartilhar a propriedade de um objeto Carro entre duas funções.

    Imprima o número de referências ao std::shared_ptr antes e depois de compartilhá-lo.
*/

class Carro
{
public:
    std::string modelo;
    int ano;

    Carro(const std::string &modelo, int ano) : modelo(modelo), ano(ano)
    {
        std::cout << "Carro criado: " << modelo << " (" << ano << ")\n";
    }

    ~Carro()
    {
        std::cout << "Carro destruído: " << modelo << " (" << ano << ")\n";
    }
};

void funcao1(std::shared_ptr<Carro> carro)
{
    std::cout << "Funcao1 - Modelo: " << carro->modelo << ", Ano: " << carro->ano << "\n";
    std::cout << "Número de referências em funcao1: " << carro.use_count() << "\n";
}

void funcao2(std::shared_ptr<Carro> carro)
{
    std::cout << "Funcao2 - Modelo: " << carro->modelo << ", Ano: " << carro->ano << "\n";
    std::cout << "Número de referências em funcao2: " << carro.use_count() << "\n";
}

int main()
{
    // Criando um shared_ptr para um objeto Carro
    std::shared_ptr<Carro> carro = std::make_shared<Carro>("Fusca", 1970);

    // Imprimindo o número de referências antes de compartilhar
    std::cout << "Número de referências após criação: " << carro.use_count() << "\n";

    // Passando o shared_ptr para as funções
    funcao1(carro);
    funcao2(carro);

    // Imprimindo o número de referências após compartilhar
    std::cout << "Número de referências após compartilhamento: " << carro.use_count() << "\n";

    // O shared_ptr será automaticamente destruído quando sair do escopo
    return 0;
}