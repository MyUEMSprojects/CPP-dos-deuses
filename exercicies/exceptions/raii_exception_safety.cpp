#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

/*
. Segurança contra exceções com RAII

    Um `Transaction` representa uma operação que modifica uma lista de
    inteiros. Se qualquer passo lançar uma exceção no meio do caminho, as
    modificações feitas até ali devem ser desfeitas automaticamente
    (rollback), sem precisar de um bloco catch manual em cada função que
    mexe na lista.

    A ideia: o destrutor de Transaction desfaz as mudanças a menos que
    commit() tenha sido chamado (mesmo padrão usado por std::unique_ptr:
    "ação automática no fim do escopo").
*/

class Transaction
{
public:
    explicit Transaction(std::vector<int> &data) : data_(data), originalSize_(data.size()) {}

    ~Transaction()
    {
        if (!committed_)
        {
            std::cout << "Rollback: desfazendo alterações (voltando para " << originalSize_ << " elementos).\n";
            data_.resize(originalSize_);
        }
    }

    void commit()
    {
        committed_ = true;
    }

private:
    std::vector<int> &data_;
    std::size_t originalSize_;
    bool committed_ = false;
};

void addValues(std::vector<int> &data, const std::vector<int> &values, bool simulateFailure)
{
    Transaction tx(data);

    for (int v : values)
    {
        data.push_back(v);
        if (simulateFailure && v == 3)
        {
            throw std::runtime_error("Falha simulada ao inserir o valor 3!");
        }
    }

    tx.commit(); // só confirma se todos os valores foram inseridos com sucesso
}

int main()
{
    std::vector<int> numbers = {1, 2};

    try
    {
        addValues(numbers, {10, 20, 3, 40}, /*simulateFailure=*/true);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro capturado: " << e.what() << "\n";
    }

    std::cout << "Tamanho após falha (deve ser 2): " << numbers.size() << "\n";

    addValues(numbers, {10, 20, 30}, /*simulateFailure=*/false);
    std::cout << "Tamanho após sucesso (deve ser 5): " << numbers.size() << "\n";

    return 0;
}
