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
class User
{
public:
    User(const std::string &name) : name(name) {}
    std::string getName() const { return name; }

private:
    std::string name;
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

    void doSomething()
    {
        std::cout << "Singleton está fazendo algo.\n";
    }

private:
    Singleton() {}                                    // Construtor privado
    Singleton(const Singleton &) = delete;            // Evitar cópia
    Singleton &operator=(const Singleton &) = delete; // Evitar atribuição
};

// Factory: Cria objetos sem especificar a classe exata.
class Product
{
public:
    virtual void use() = 0;
    virtual ~Product() = default;
};

class ProductA : public Product
{
public:
    void use() override
    {
        std::cout << "Usando Produto A.\n";
    }
};

class ProductB : public Product
{
public:
    void use() override
    {
        std::cout << "Usando Produto B.\n";
    }
};

class Factory
{
public:
    static std::unique_ptr<Product> createProduct(const std::string &type)
    {
        if (type == "A")
        {
            return std::make_unique<ProductA>();
        }
        else if (type == "B")
        {
            return std::make_unique<ProductB>();
        }
        return nullptr;
    }
};

// Observer: Notifica objetos sobre mudanças de estado.
class Observer
{
public:
    virtual void update(const std::string &message) = 0;
    virtual ~Observer() = default;
};

class Subject
{
public:
    void addObserver(std::shared_ptr<Observer> observer)
    {
        observers.push_back(observer);
    }

    void notify(const std::string &message)
    {
        for (const auto &observer : observers)
        {
            observer->update(message);
        }
    }

private:
    std::vector<std::shared_ptr<Observer>> observers;
};

class ConcreteObserver : public Observer
{
public:
    void update(const std::string &message) override
    {
        std::cout << "Observador recebeu: " << message << "\n";
    }
};

// 3. Uso de namespaces
namespace MyApp
{
    void run()
    {
        std::cout << "Função dentro do namespace MyApp.\n";
    }
}

// 4. Const-correctness
class ConstExample
{
public:
    void constMethod() const
    {
        std::cout << "Método const chamado.\n";
    }

    void nonConstMethod()
    {
        std::cout << "Método não const chamado.\n";
    }
};

// 5. Prevenção de vazamentos de memória e dangling pointers
void smartPointersExample()
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
    User user("João");
    std::cout << "Nome do usuário: " << user.getName() << "\n";

    // 2. Design Patterns
    // Singleton
    Singleton::getInstance().doSomething();

    // Factory
    auto productA = Factory::createProduct("A");
    productA->use();

    auto productB = Factory::createProduct("B");
    productB->use();

    // Observer
    Subject subject;
    auto observer = std::make_shared<ConcreteObserver>();
    subject.addObserver(observer);
    subject.notify("Mensagem de notificação");

    // 3. Uso de namespaces
    MyApp::run();

    // 4. Const-correctness
    ConstExample example;
    example.constMethod();
    example.nonConstMethod();

    const ConstExample constExample;
    constExample.constMethod();
    // constExample.nonConstMethod(); // Erro: Não pode chamar método não const em objeto const

    // 5. Prevenção de vazamentos de memória e dangling pointers
    smartPointersExample();

    return 0;
}
