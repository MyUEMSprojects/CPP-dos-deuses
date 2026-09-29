#include <iostream>
#include <memory> // Para std::make_unique e std::make_shared
#include <string>

// Classe Product
class Product
{
public:
    // Construtor
    Product(const std::string &name, double price) : name_(name), price_(price)
    {
        std::cout << "Produto criado: " << name_ << " (R$ " << price_ << ")\n";
    }

    // Destrutor
    ~Product()
    {
        std::cout << "Produto destruído: " << name_ << "\n";
    }

    // Métodos para acessar os atributos
    std::string get_name() const
    {
        return name_;
    }

    double get_price() const
    {
        return price_;
    }

private:
    std::string name_;
    double price_;
};

// Função que recebe um std::shared_ptr<Product>
void display_product_shared(const std::shared_ptr<Product> &product)
{
    std::cout << "Exibindo produto (shared): " << product->get_name()
              << " (R$ " << product->get_price() << ")\n";
}

// Função que recebe um std::unique_ptr<Product>
void display_product_unique(const std::unique_ptr<Product> &product)
{
    std::cout << "Exibindo produto (unique): " << product->get_name()
              << " (R$ " << product->get_price() << ")\n";
}

int main()
{
    // Cria um Product usando std::make_unique
    auto unique_product = std::make_unique<Product>("Notebook", 3500.0);

    // Exibe o produto usando std::unique_ptr
    display_product_unique(unique_product);

    // Converte o std::unique_ptr para std::shared_ptr
    std::shared_ptr<Product> shared_product = std::move(unique_product);

    // Exibe o produto usando std::shared_ptr
    display_product_shared(shared_product);

    // Cria outro std::shared_ptr que compartilha a propriedade do mesmo produto
    auto another_shared = shared_product;

    // Exibe o produto novamente
    display_product_shared(another_shared);

    // Mostra a contagem de referências do std::shared_ptr
    std::cout << "Contagem de referências: " << shared_product.use_count() << "\n";

    return 0;
}
