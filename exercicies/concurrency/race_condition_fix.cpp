#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

/*
. Condição de corrida (race condition) e como corrigi-la

    increment_unsafe() abaixo tem uma race condition clássica: várias
    threads fazem `counter++` ao mesmo tempo sem sincronização, então o
    resultado final quase sempre é menor que o esperado (10 threads x
    100000 incrementos deveria dar 1000000).

    increment_safe() corrige o problema com std::mutex. Rode o programa
    algumas vezes e compare os dois resultados — o "unsafe" costuma variar
    a cada execução (comportamento indefinido / não determinístico), o
    "safe" é sempre 1000000.
*/

constexpr int kThreads = 10;
constexpr int kIncrementsPerThread = 100000;

int unsafeCounter = 0;

void increment_unsafe()
{
    for (int i = 0; i < kIncrementsPerThread; ++i)
    {
        ++unsafeCounter; // não atômico: leitura + escrita podem intercalar entre threads
    }
}

int safeCounter = 0;
std::mutex counterMutex;

void increment_safe()
{
    for (int i = 0; i < kIncrementsPerThread; ++i)
    {
        std::lock_guard<std::mutex> lock(counterMutex);
        ++safeCounter;
    }
}

int main()
{
    // Versão com race condition
    {
        std::vector<std::thread> threads;
        for (int i = 0; i < kThreads; ++i)
        {
            threads.emplace_back(increment_unsafe);
        }
        for (auto &t : threads)
        {
            t.join();
        }
        std::cout << "Contador sem sincronização (esperado " << kThreads * kIncrementsPerThread
                  << "): " << unsafeCounter << "\n";
    }

    // Versão corrigida com mutex
    {
        std::vector<std::thread> threads;
        for (int i = 0; i < kThreads; ++i)
        {
            threads.emplace_back(increment_safe);
        }
        for (auto &t : threads)
        {
            t.join();
        }
        std::cout << "Contador com mutex (esperado " << kThreads * kIncrementsPerThread
                  << "): " << safeCounter << "\n";
    }

    return 0;
}
