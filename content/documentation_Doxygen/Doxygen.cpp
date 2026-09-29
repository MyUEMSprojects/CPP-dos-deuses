#include <iostream>
#include <string>

/**
 * @brief Classe que representa um usuário.
 *
 * Esta classe armazena o nome de um usuário e fornece métodos para acessá-lo.
 */
class User
{
public:
    /**
     * @brief Construtor da classe User.
     * @param name Nome do usuário.
     */
    User(const std::string &name) : name_(name) {}

    /**
     * @brief Obtém o nome do usuário.
     * @return O nome do usuário.
     */
    std::string get_name() const
    {
        return name_;
    }

private:
    std::string name_; ///< Nome do usuário.
};

/**
 * @brief Função que imprime uma mensagem de boas-vindas.
 * @param name Nome do usuário a ser saudado.
 */
void greet(const std::string &name)
{
    std::cout << "Olá, " << name << "!\n";
}

int main()
{
    // Cria um objeto User
    User user("João");

    // Sauda o usuário
    greet(user.get_name());

    return 0;
}
