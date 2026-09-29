#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

/*
. Produtor-consumidor com condition_variable

    Implemente uma fila thread-safe (SharedQueue) usada por uma thread
    produtora, que insere itens, e uma thread consumidora, que os remove.
    A consumidora deve dormir (sem busy-wait) enquanto a fila está vazia,
    acordando via condition_variable assim que um item chega.
*/

template <typename T>
class SharedQueue
{
public:
    void push(T value)
    {
        {
            std::lock_guard<std::mutex> lock(mutex_);
            queue_.push(std::move(value));
        }
        cv_.notify_one();
    }

    // Bloqueia até haver um item disponível, então o remove e retorna.
    T waitAndPop()
    {
        std::unique_lock<std::mutex> lock(mutex_);
        cv_.wait(lock, [this]
                 { return !queue_.empty(); });
        T value = std::move(queue_.front());
        queue_.pop();
        return value;
    }

private:
    std::queue<T> queue_;
    std::mutex mutex_;
    std::condition_variable cv_;
};

constexpr int kItemCount = 10;

void producer(SharedQueue<int> &queue)
{
    for (int i = 1; i <= kItemCount; ++i)
    {
        std::cout << "Produzindo item " << i << "\n";
        queue.push(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
    queue.push(-1); // valor "sentinela" para sinalizar o fim ao consumidor
}

void consumer(SharedQueue<int> &queue)
{
    while (true)
    {
        int item = queue.waitAndPop();
        if (item == -1)
        {
            break;
        }
        std::cout << "  Consumindo item " << item << "\n";
    }
}

int main()
{
    SharedQueue<int> queue;

    std::thread producerThread(producer, std::ref(queue));
    std::thread consumerThread(consumer, std::ref(queue));

    producerThread.join();
    consumerThread.join();

    std::cout << "Produção e consumo concluídos.\n";
    return 0;
}
