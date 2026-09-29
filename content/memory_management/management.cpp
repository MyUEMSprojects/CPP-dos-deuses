#include <iostream>
#include <memory> // Para smart pointers

// 1. Alocação dinâmica de memória (new e delete)
void newDeleteExample()
{
    int *ptr = new int(42); // Aloca memória para um int e inicializa com 42
    std::cout << "Valor alocado dinamicamente: " << *ptr << "\n";
    delete ptr; // Libera a memória alocada
}

// 2. Ponteiros e referências
void pointersReferencesExample()
{
    int value = 10;
    int *ptr = &value; // Ponteiro para value
    int &ref = value;  // Referência para value

    std::cout << "Valor original: " << value << "\n";
    *ptr = 20; // Modifica value através do ponteiro
    std::cout << "Valor após modificar via ponteiro: " << value << "\n";
    ref = 30; // Modifica value através da referência
    std::cout << "Valor após modificar via referência: " << value << "\n";
}

// 3. Smart pointers (unique_ptr, shared_ptr, weak_ptr)
void smartPointersExample()
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
class Resource
{
public:
    Resource()
    {
        std::cout << "Recurso alocado.\n";
    }

    ~Resource()
    {
        std::cout << "Recurso liberado.\n";
    }

    void use()
    {
        std::cout << "Recurso em uso.\n";
    }
};

void raiiExample()
{
    // RAII: O recurso é liberado automaticamente quando o objeto sai do escopo
    Resource resource;
    resource.use();
}

int main()
{
    std::cout << "=== Exemplo de new/delete ===\n";
    newDeleteExample();

    std::cout << "\n=== Exemplo de ponteiros e referências ===\n";
    pointersReferencesExample();

    std::cout << "\n=== Exemplo de smart pointers ===\n";
    smartPointersExample();

    std::cout << "\n=== Exemplo de RAII ===\n";
    raiiExample();

    return 0;
}
