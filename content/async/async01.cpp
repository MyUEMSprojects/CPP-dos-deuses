#include <iostream>
#include <future>
#include <thread>
#include <chrono>
#include <vector>

// Função que simula uma operação lenta
int slowOperation(int id, int duration) {
    std::cout << "Iniciando tarefa " << id << "..." << std::endl;
    // Simula um processamento demorado
    std::this_thread::sleep_for(std::chrono::seconds(duration));
    std::cout << "Tarefa " << id << " concluída!" << std::endl;
    return id * 10;
}

int main() {
    // Início da contagem de tempo
    auto start = std::chrono::high_resolution_clock::now();

    // Cria várias tarefas assíncronas
    std::vector<std::future<int>> tasks;

    // Inicia 3 tarefas assíncronas
    for (int i = 1; i <= 3; ++i) {
        // std::async lança uma nova thread para executar a função
        tasks.push_back(std::async(std::launch::async, slowOperation, i, i));
    }

    // Faz outras coisas enquanto as tarefas rodam...
    std::cout << "Tarefas iniciadas em background. Fazendo outro trabalho..." << std::endl;

    // Espera e obtém resultados de todas as tarefas
    int sum = 0;
    for (auto& task : tasks) {
        // .get() espera pela conclusão e retorna o resultado
        sum += task.get();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();

    std::cout << "Soma dos resultados: " << sum << std::endl;
    std::cout << "Tempo total: " << elapsed << " segundos" << std::endl;

    return 0;
}
