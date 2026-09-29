#include <iostream>
#include <memory> // Para std::shared_ptr e std::make_shared

// Classe Resource
class Resource
{
public:
    // Construtor: aloca dinamicamente um array de inteiros
    Resource(int size) : size_(size)
    {
        data_ = new int[size_];
        std::cout << "Recurso alocado: array de " << size_ << " inteiros.\n";
    }

    // Método para acessar o array
    int *get_data() const
    {
        return data_;
    }

    // Método para exibir os dados
    void display_data() const
    {
        std::cout << "Dados: ";
        for (int i = 0; i < size_; ++i)
        {
            std::cout << data_[i] << " ";
        }
        std::cout << "\n";
    }

private:
    int *data_; // Array de inteiros
    int size_;  // Tamanho do array

    // Custom deleter: recebe o próprio Resource, libera o array e o objeto
    static void release_resource(Resource *ptr)
    {
        std::cout << "Recurso liberado.\n";
        delete[] ptr->data_; // Libera o array de inteiros
        delete ptr;          // Libera o objeto Resource
    }

public:
    // Método estático para criar um std::shared_ptr com custom deleter
    static std::shared_ptr<Resource> create(int size)
    {
        // Cria um Resource e usa o custom deleter
        return std::shared_ptr<Resource>(new Resource(size), release_resource);
    }
};

int main()
{
    // Cria um std::shared_ptr<Resource> com custom deleter
    auto resource = Resource::create(5);

    // Preenche o array com valores
    int *data = resource->get_data();
    for (int i = 0; i < 5; ++i)
    {
        data[i] = i + 1;
    }

    // Exibe os dados
    resource->display_data();

    // O recurso será liberado automaticamente quando o shared_ptr sair do escopo
    return 0;
}
