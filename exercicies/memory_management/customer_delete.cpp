#include <iostream>
#include <memory> // Para std::shared_ptr e std::make_shared

// Classe Recurso
class Recurso
{
public:
    // Construtor: aloca dinamicamente um array de inteiros
    Recurso(int tamanho) : tamanho_(tamanho)
    {
        dados_ = new int[tamanho_];
        std::cout << "Recurso alocado: array de " << tamanho_ << " inteiros.\n";
    }

    // Método para acessar o array
    int *get_dados() const
    {
        return dados_;
    }

    // Método para exibir os dados
    void exibir_dados() const
    {
        std::cout << "Dados: ";
        for (int i = 0; i < tamanho_; ++i)
        {
            std::cout << dados_[i] << " ";
        }
        std::cout << "\n";
    }

private:
    int *dados_;  // Array de inteiros
    int tamanho_; // Tamanho do array

    // Custom deleter: libera a memória alocada
    static void liberar_recurso(int *ptr)
    {
        std::cout << "Recurso liberado.\n";
        delete[] ptr; // Libera o array de inteiros
    }

public:
    // Método estático para criar um std::shared_ptr com custom deleter
    static std::shared_ptr<Recurso> criar(int tamanho)
    {
        // Cria um Recurso e usa o custom deleter
        return std::shared_ptr<Recurso>(new Recurso(tamanho), liberar_recurso);
    }
};

int main()
{
    // Cria um std::shared_ptr<Recurso> com custom deleter
    auto recurso = Recurso::criar(5);

    // Preenche o array com valores
    int *dados = recurso->get_dados();
    for (int i = 0; i < 5; ++i)
    {
        dados[i] = i + 1;
    }

    // Exibe os dados
    recurso->exibir_dados();

    // O recurso será liberado automaticamente quando o shared_ptr sair do escopo
    return 0;
}