#include <iostream>
#include <string>

/**
 * @brief Classe que representa um usuário.
 *
 * Esta classe armazena o nome de um usuário e fornece métodos para acessá-lo.
 */
class Usuario
{
public:
    /**
     * @brief Construtor da classe Usuario.
     * @param nome Nome do usuário.
     */
    Usuario(const std::string &nome) : nome_(nome) {}

    /**
     * @brief Obtém o nome do usuário.
     * @return O nome do usuário.
     */
    std::string get_nome() const
    {
        return nome_;
    }

private:
    std::string nome_; ///< Nome do usuário.
};

/**
 * @brief Função que imprime uma mensagem de boas-vindas.
 * @param nome Nome do usuário a ser saudado.
 */
void saudar(const std::string &nome)
{
    std::cout << "Olá, " << nome << "!\n";
}

int main()
{
    // Cria um objeto Usuario
    Usuario usuario("João");

    // Sauda o usuário
    saudar(usuario.get_nome());

    return 0;
}