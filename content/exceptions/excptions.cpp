#include <iostream>
#include <memory>
#include <stdexcept> // Para std::exception e std::runtime_error

// 1. Tratamento de exceções básico
void basicExample() {
    try {
        int age;
        std::cout << "Digite sua idade: ";
        std::cin >> age;

        if (age < 0) {
            throw std::runtime_error("Idade não pode ser negativa!"); // Lança uma exceção
        }

        std::cout << "Sua idade é: " << age << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << "\n"; // Captura e trata a exceção
    }
}

// 2. Criação de exceções personalizadas
class InvalidAgeException : public std::exception {
public:
    InvalidAgeException(const std::string& message) : message(message) {}

    const char* what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message;
};

void customExceptionExample() {
    try {
        int age;
        std::cout << "Digite sua idade: ";
        std::cin >> age;

        if (age < 0) {
            throw InvalidAgeException("Idade não pode ser negativa!"); // Lança exceção personalizada
        }

        std::cout << "Sua idade é: " << age << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << "\n"; // Captura e trata a exceção
    }
}

// 3. Boas práticas no uso de exceções
void bestPracticesExample() {
    try {
        int* ptr = new int(42); // Alocação dinâmica de memória

        // Simulando um erro
        throw std::runtime_error("Erro durante a execução!");

        delete ptr; // Isso nunca será executado se uma exceção for lançada
    } catch (const std::exception& e) {
        std::cerr << "Erro capturado: " << e.what() << "\n";
    }

    // Uso de RAII para gerenciar recursos
    try {
        std::unique_ptr<int> ptr = std::make_unique<int>(42); // Smart pointer para gerenciar memória

        // Simulando um erro
        throw std::runtime_error("Erro durante a execução!");

        // Não precisamos nos preocupar com delete, o smart pointer cuida disso
    } catch (const std::exception& e) {
        std::cerr << "Erro capturado: " << e.what() << "\n";
    }
}

int main() {
    std::cout << "=== Exemplo básico de tratamento de exceções ===\n";
    basicExample();

    std::cout << "\n=== Exemplo de exceção personalizada ===\n";
    customExceptionExample();

    std::cout << "\n=== Exemplo de boas práticas com exceções ===\n";
    bestPracticesExample();

    return 0;
}
