#include <iostream>
#include <stdexcept>
#include <string>

/*
. Hierarquia de exceções personalizadas

    Modele uma conta bancária simples (BankAccount) cujo método withdraw()
    lança:
      - InsufficientFundsException quando o valor solicitado é maior que o
        saldo disponível;
      - InvalidAmountException quando o valor solicitado é <= 0.

    Ambas devem herdar de uma base comum BankException, para que o
    chamador possa optar por capturar cada erro especificamente ou capturar
    todos de uma vez via `catch (const BankException&)`.
*/

class BankException : public std::runtime_error
{
public:
    explicit BankException(const std::string &message) : std::runtime_error(message) {}
};

class InsufficientFundsException : public BankException
{
public:
    InsufficientFundsException(double requested, double available)
        : BankException("Saldo insuficiente: solicitado " + std::to_string(requested) +
                         ", disponível " + std::to_string(available)) {}
};

class InvalidAmountException : public BankException
{
public:
    explicit InvalidAmountException(double amount)
        : BankException("Valor inválido para saque: " + std::to_string(amount)) {}
};

class BankAccount
{
public:
    explicit BankAccount(double initialBalance) : balance_(initialBalance) {}

    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            throw InvalidAmountException(amount);
        }
        if (amount > balance_)
        {
            throw InsufficientFundsException(amount, balance_);
        }
        balance_ -= amount;
    }

    double balance() const { return balance_; }

private:
    double balance_;
};

int main()
{
    BankAccount account(100.0);

    // Captura específica
    try
    {
        account.withdraw(150.0);
    }
    catch (const InsufficientFundsException &e)
    {
        std::cerr << "Erro específico: " << e.what() << "\n";
    }

    // Captura genérica via classe base
    try
    {
        account.withdraw(-10.0);
    }
    catch (const BankException &e)
    {
        std::cerr << "Erro genérico (BankException): " << e.what() << "\n";
    }

    account.withdraw(30.0);
    std::cout << "Saldo final: " << account.balance() << "\n";

    return 0;
}
