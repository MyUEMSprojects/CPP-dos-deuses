#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <atomic>
#include <vector>

// 1. Threads (std::thread)
void threadFunction(int id)
{
    std::cout << "Thread " << id << " em execução.\n";
}

// 2. Mutexes e locks (std::mutex, std::lock_guard, std::unique_lock)
std::mutex mtx;
int counter = 0;

void incrementCounter()
{
    for (int i = 0; i < 1000; ++i)
    {
        std::lock_guard<std::mutex> lock(mtx); // Bloqueia o mutex
        ++counter;
    }
}

// 3. Condition variables
std::condition_variable cv;
bool ready = false;

void waitUntilReady()
{
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []
            { return ready; }); // Espera até que "ready" seja true
    std::cout << "Pronto! Continuando a execução.\n";
}

void setReady()
{
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simula um atraso
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;
    }
    cv.notify_all(); // Notifica todas as threads em espera
}

// 4. Futures e promises (std::future, std::promise)
int calculateSquare(int x)
{
    return x * x;
}

void futurePromiseExample()
{
    std::promise<int> promise;
    std::future<int> future = promise.get_future();

    std::thread t([&promise]
                  {
                      int result = calculateSquare(5);
                      promise.set_value(result); // Define o valor da promise
                  });

    std::cout << "Quadrado de 5: " << future.get() << "\n"; // Obtém o valor do future
    t.join();
}

// 5. Atomics
std::atomic<int> atomicCounter(0);

void incrementAtomicCounter()
{
    for (int i = 0; i < 1000; ++i)
    {
        ++atomicCounter; // Operação atômica
    }
}

int main()
{
    // 1. Threads (std::thread)
    std::thread t1(threadFunction, 1);
    std::thread t2(threadFunction, 2);
    t1.join();
    t2.join();

    // 2. Mutexes e locks (std::mutex, std::lock_guard, std::unique_lock)
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i)
    {
        threads.emplace_back(incrementCounter);
    }
    for (auto &t : threads)
    {
        t.join();
    }
    std::cout << "Contador: " << counter << "\n";

    // 3. Condition variables
    std::thread t3(waitUntilReady);
    std::thread t4(setReady);
    t3.join();
    t4.join();

    // 4. Futures e promises (std::future, std::promise)
    futurePromiseExample();

    // 5. Atomics
    std::vector<std::thread> atomicThreads;
    for (int i = 0; i < 10; ++i)
    {
        atomicThreads.emplace_back(incrementAtomicCounter);
    }
    for (auto &t : atomicThreads)
    {
        t.join();
    }
    std::cout << "Contador atômico: " << atomicCounter << "\n";

    return 0;
}
