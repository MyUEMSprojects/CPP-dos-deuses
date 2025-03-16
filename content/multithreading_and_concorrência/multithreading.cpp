#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <atomic>
#include <vector>

// 1. Threads (std::thread)
void funcaoThread(int id)
{
    std::cout << "Thread " << id << " em execução.\n";
}

// 2. Mutexes e locks (std::mutex, std::lock_guard, std::unique_lock)
std::mutex mtx;
int contador = 0;

void incrementarContador()
{
    for (int i = 0; i < 1000; ++i)
    {
        std::lock_guard<std::mutex> lock(mtx); // Bloqueia o mutex
        ++contador;
    }
}

// 3. Condition variables
std::condition_variable cv;
bool pronto = false;

void esperarPronto()
{
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []
            { return pronto; }); // Espera até que "pronto" seja true
    std::cout << "Pronto! Continuando a execução.\n";
}

void definirPronto()
{
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simula um atraso
    {
        std::lock_guard<std::mutex> lock(mtx);
        pronto = true;
    }
    cv.notify_all(); // Notifica todas as threads em espera
}

// 4. Futures e promises (std::future, std::promise)
int calcularQuadrado(int x)
{
    return x * x;
}

void exemploFuturePromise()
{
    std::promise<int> promessa;
    std::future<int> futuro = promessa.get_future();

    std::thread t([&promessa]
                  {
                      int resultado = calcularQuadrado(5);
                      promessa.set_value(resultado); // Define o valor da promessa
                  });

    std::cout << "Quadrado de 5: " << futuro.get() << "\n"; // Obtém o valor do futuro
    t.join();
}

// 5. Atomics
std::atomic<int> contadorAtomico(0);

void incrementarContadorAtomico()
{
    for (int i = 0; i < 1000; ++i)
    {
        ++contadorAtomico; // Operação atômica
    }
}

int main()
{
    // 1. Threads (std::thread)
    std::thread t1(funcaoThread, 1);
    std::thread t2(funcaoThread, 2);
    t1.join();
    t2.join();

    // 2. Mutexes e locks (std::mutex, std::lock_guard, std::unique_lock)
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i)
    {
        threads.emplace_back(incrementarContador);
    }
    for (auto &t : threads)
    {
        t.join();
    }
    std::cout << "Contador: " << contador << "\n";

    // 3. Condition variables
    std::thread t3(esperarPronto);
    std::thread t4(definirPronto);
    t3.join();
    t4.join();

    // 4. Futures e promises (std::future, std::promise)
    exemploFuturePromise();

    // 5. Atomics
    std::vector<std::thread> threadsAtomicas;
    for (int i = 0; i < 10; ++i)
    {
        threadsAtomicas.emplace_back(incrementarContadorAtomico);
    }
    for (auto &t : threadsAtomicas)
    {
        t.join();
    }
    std::cout << "Contador atômico: " << contadorAtomico << "\n";

    return 0;
}