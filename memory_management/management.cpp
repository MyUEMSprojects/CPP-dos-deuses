#include <iostream>
#include <memory> // Para smart pointers

// 1. Alocação dinâmica de memória (new e delete)
void exemploNewDelete()
{
    int *ptr = new int(42); // Aloca memória para um int e inicializa com 42
    std::cout << "Valor alocado dinamicamente: " << *ptr << "\n";
    delete ptr; // Libera a memória alocada
}

// 2. Ponteiros e referências
void exemploPonteirosReferencias()
{
    int valor = 10;
    int *ptr = &valor; // Ponteiro para valor
    int &ref = valor;  // Referência para valor

    std::cout << "Valor original: " << valor << "\n";
    *ptr = 20; // Modifica valor através do ponteiro
    std::cout << "Valor após modificar via ponteiro: " << valor << "\n";
    ref = 30; // Modifica valor através da referência
    std::cout << "Valor após modificar via referência: " << valor << "\n";
}

// 3. Smart pointers (unique_ptr, shared_ptr, weak_ptr)
void exemploSmartPointers()
{
    // unique_ptr: Ponteiro único (não pode ser copiado)
    std::unique_ptr<int> uniquePtr = std::make_unique<int>(100);
    std::cout << "Valor no unique_ptr: " << *uniquePtr << "\n";

    // shared_ptr: Ponteiro compartilhado (contagem de referências)
    std::shared_ptr<int> sharedPtr1 = std::make_shared<int>(200);
    std::shared_ptr<int> sharedPtr2 = sharedPtr1; // Copia o shared_ptr
    std::cout << "Valor no shared_ptr1: " << *sharedPtr1 << "\n";
    std::cout << "Valor no shared_ptr2: " << *sharedPtr2 << "\n";
    std::cout << "Contagem de referências: " << sharedPtr1.use_count() << "\n";

    // weak_ptr: Ponteiro fraco (não aumenta a contagem de referências)
    std::weak_ptr<int> weakPtr = sharedPtr1;
    if (auto tempPtr = weakPtr.lock())
    {
        std::cout << "Valor no weak_ptr: " << *tempPtr << "\n";
    }
    else
    {
        std::cout << "Objeto já foi destruído.\n";
    }
}

// 4. Gerenciamento de recursos e RAII
class Recurso
{
public:
    Recurso()
    {
        std::cout << "Recurso alocado.\n";
    }

    ~Recurso()
    {
        std::cout << "Recurso liberado.\n";
    }

    void usar()
    {
        std::cout << "Recurso em uso.\n";
    }
};

void exemploRAII()
{
    // RAII: O recurso é liberado automaticamente quando o objeto sai do escopo
    Recurso recurso;
    recurso.usar();
}

int main()
{
    std::cout << "=== Exemplo de new/delete ===\n";
    exemploNewDelete();

    std::cout << "\n=== Exemplo de ponteiros e referências ===\n";
    exemploPonteirosReferencias();

    std::cout << "\n=== Exemplo de smart pointers ===\n";
    exemploSmartPointers();

    std::cout << "\n=== Exemplo de RAII ===\n";
    exemploRAII();

    return 0;
}