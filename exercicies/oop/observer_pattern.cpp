#include <iostream>
#include <functional>
#include <string>
#include <vector>

/*
. Padrão Observer (sem herança, com std::function)

    Implemente um StockTicker que notifica todos os observadores
    inscritos sempre que o preço de uma ação muda. Em vez de exigir que
    cada observador herde de uma interface Observer, use std::function
    para aceitar qualquer callable (lambda, função livre, functor).
*/

class StockTicker
{
public:
    using Listener = std::function<void(const std::string &symbol, double price)>;

    void subscribe(Listener listener)
    {
        listeners_.push_back(std::move(listener));
    }

    void updatePrice(const std::string &symbol, double price)
    {
        for (const auto &listener : listeners_)
        {
            listener(symbol, price);
        }
    }

private:
    std::vector<Listener> listeners_;
};

int main()
{
    StockTicker ticker;

    // Observador 1: lambda simples
    ticker.subscribe([](const std::string &symbol, double price)
                      { std::cout << "[Log] " << symbol << " agora vale R$ " << price << "\n"; });

    // Observador 2: lambda com estado próprio (alerta de queda)
    double lastPrice = 0.0;
    ticker.subscribe([lastPrice](const std::string &symbol, double price) mutable
                      {
                          if (lastPrice != 0.0 && price < lastPrice)
                          {
                              std::cout << "[Alerta] " << symbol << " caiu! " << lastPrice << " -> " << price << "\n";
                          }
                          lastPrice = price;
                      });

    ticker.updatePrice("PETR4", 32.10);
    ticker.updatePrice("PETR4", 31.50);
    ticker.updatePrice("PETR4", 33.00);

    return 0;
}
