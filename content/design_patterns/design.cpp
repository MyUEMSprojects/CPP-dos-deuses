#include <iostream>
#include <memory>
#include <vector>
#include <unordered_map>

// 1. Princípios SOLID
// - Single Responsibility Principle (SRP): Uma classe deve ter apenas uma razão para mudar.
// - Open/Closed Principle (OCP): Classes devem ser abertas para extensão, mas fechadas para modificação.
// - Liskov Substitution Principle (LSP): Objetos de uma classe base devem ser substituíveis por objetos de uma classe derivada.
// - Interface Segregation Principle (ISP): Muitas interfaces específicas são melhores que uma interface geral.
// - Dependency Inversion Principle (DIP): Dependa de abstrações, não de implementações.

// Exemplo de SRP: Uma classe que gerencia apenas a lógica de um usuário.
class Usuario
{
public:
    Usuario(const std::string &nome) : nome(nome) {}
    std::string getNome() const { return nome; }

private:
    std::string nome;
};

// 2. Design Patterns
// Singleton: Garante que uma classe tenha apenas uma instância.
class Singleton
{
public:
    static Singleton &getInstance()
    {
        static Singleton instance;
        return instance;
    }

    void fazerAlgo()
    {
        std::cout << "Singleton está fazendo algo.\n";
    }

private:
    Singleton() {}                                    // Construtor privado
    Singleton(const Singleton &) = delete;            // Evitar cópia
    Singleton &operator=(const Singleton &) = delete; // Evitar atribuição
};

// Factory: Cria objetos sem especificar a classe exata.
class Produto
{
public:
    virtual void usar() = 0;
    virtual ~Produto() = default;
};

class ProdutoA : public Produto
{
public:
    void usar() override
    {
        std::cout << "Usando Produto A.\n";
    }
};

class ProdutoB : public Produto
{
public:
    void usar() override
    {
        std::cout << "Usando Produto B.\n";
    }
};

class Fabrica
{
public:
    static std::unique_ptr<Produto> criarProduto(const std::string &tipo)
    {
        if (tipo == "A")
        {
            return std::make_unique<ProdutoA>();
        }
        else if (tipo == "B")
        {
            return std::make_unique<ProdutoB>();
        }
        return nullptr;
    }
};

// Observer: Notifica objetos sobre mudanças de estado.
class Observer
{
public:
    virtual void atualizar(const std::string &mensagem) = 0;
    virtual ~Observer() = default;
};

class Assunto
{
public:
    void adicionarObserver(std::shared_ptr<Observer> observer)
    {
        observers.push_back(observer);
    }

    void notificar(const std::string &mensagem)
    {
        for (const auto &observer : observers)
        {
            observer->atualizar(mensagem);
        }
    }

private:
    std::vector<std::shared_ptr<Observer>> observers;
};

class ObservadorConcreto : public Observer
{
public:
    void atualizar(const std::string &mensagem) override
    {
        std::cout << "Observador recebeu: " << mensagem << "\n";
    }
};

// 3. Uso de namespaces
namespace MinhaAplicacao
{
    void funcao()
    {
        std::cout << "Função dentro do namespace MinhaAplicacao.\n";
    }
}

// 4. Const-correctness
class ExemploConst
{
public:
    void metodoConst() const
    {
        std::cout << "Método const chamado.\n";
    }

    void metodoNaoConst()
    {
        std::cout << "Método não const chamado.\n";
    }
};

// 5. Prevenção de vazamentos de memória e dangling pointers
void exemploSmartPointers()
{
    auto ptr = std::make_unique<int>(42); // std::unique_ptr
    std::cout << "Valor: " << *ptr << "\n";

    auto sharedPtr = std::make_shared<int>(100); // std::shared_ptr
    std::cout << "Valor: " << *sharedPtr << "\n";

    std::weak_ptr<int> weakPtr = sharedPtr; // std::weak_ptr
    if (auto tempPtr = weakPtr.lock())
    {
        std::cout << "Valor via weak_ptr: " << *tempPtr << "\n";
    }
}

int main()
{
    // 1. Princípios SOLID
    Usuario usuario("João");
    std::cout << "Nome do usuário: " << usuario.getNome() << "\n";

    // 2. Design Patterns
    // Singleton
    Singleton::getInstance().fazerAlgo();

    // Factory
    auto produtoA = Fabrica::criarProduto("A");
    produtoA->usar();

    auto produtoB = Fabrica::criarProduto("B");
    produtoB->usar();

    // Observer
    Assunto assunto;
    auto observador = std::make_shared<ObservadorConcreto>();
    assunto.adicionarObserver(observador);
    assunto.notificar("Mensagem de notificação");

    // 3. Uso de namespaces
    MinhaAplicacao::funcao();

    // 4. Const-correctness
    ExemploConst exemplo;
    exemplo.metodoConst();
    exemplo.metodoNaoConst();

    const ExemploConst exemploConst;
    exemploConst.metodoConst();
    // exemploConst.metodoNaoConst(); // Erro: Não pode chamar método não const em objeto const

    // 5. Prevenção de vazamentos de memória e dangling pointers
    exemploSmartPointers();

    return 0;
}