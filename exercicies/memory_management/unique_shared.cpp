#include <iostream>
#include <memory> // Para std::make_unique e std::make_shared
#include <string>

// Classe Produto
class Produto
{
public:
    // Construtor
    Produto(const std::string &nome, double preco) : nome_(nome), preco_(preco)
    {
        std::cout << "Produto criado: " << nome_ << " (R$ " << preco_ << ")\n";
    }

    // Destrutor
    ~Produto()
    {
        std::cout << "Produto destruído: " << nome_ << "\n";
    }

    // Métodos para acessar os atributos
    std::string get_nome() const
    {
        return nome_;
    }

    double get_preco() const
    {
        return preco_;
    }

private:
    std::string nome_;
    double preco_;
};

// Função que recebe um std::shared_ptr<Produto>
void exibir_produto_shared(const std::shared_ptr<Produto> &produto)
{
    std::cout << "Exibindo produto (shared): " << produto->get_nome()
              << " (R$ " << produto->get_preco() << ")\n";
}

// Função que recebe um std::unique_ptr<Produto>
void exibir_produto_unique(const std::unique_ptr<Produto> &produto)
{
    std::cout << "Exibindo produto (unique): " << produto->get_nome()
              << " (R$ " << produto->get_preco() << ")\n";
}

int main()
{
    // Cria um Produto usando std::make_unique
    auto produto_unique = std::make_unique<Produto>("Notebook", 3500.0);

    // Exibe o produto usando std::unique_ptr
    exibir_produto_unique(produto_unique);

    // Converte o std::unique_ptr para std::shared_ptr
    std::shared_ptr<Produto> produto_shared = std::move(produto_unique);

    // Exibe o produto usando std::shared_ptr
    exibir_produto_shared(produto_shared);

    // Cria outro std::shared_ptr que compartilha a propriedade do mesmo produto
    auto outro_shared = produto_shared;

    // Exibe o produto novamente
    exibir_produto_shared(outro_shared);

    // Mostra a contagem de referências do std::shared_ptr
    std::cout << "Contagem de referências: " << produto_shared.use_count() << "\n";

    return 0;
}