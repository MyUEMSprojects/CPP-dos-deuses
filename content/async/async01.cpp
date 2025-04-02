#include <iostream>
#include <future>
#include <thread>
#include <chrono>
#include <vector>

// Função que simula uma operação lenta
int operacaoLenta(int id, int duracao) {
    std::cout << "Iniciando tarefa " << id << "..." << std::endl;
    // Simula um processamento demorado
    std::this_thread::sleep_for(std::chrono::seconds(duracao));
    std::cout << "Tarefa " << id << " concluída!" << std::endl;
    return id * 10;
}

int main() {
    // Início da contagem de tempo
    auto inicio = std::chrono::high_resolution_clock::now();
    
    // Cria várias tarefas assíncronas
    std::vector<std::future<int>> tarefas;
    
    // Inicia 3 tarefas assíncronas
    for (int i = 1; i <= 3; ++i) {
        // std::async lança uma nova thread para executar a função
        tarefas.push_back(std::async(std::launch::async, operacaoLenta, i, i));
    }
    
    // Faz outras coisas enquanto as tarefas rodam...
    std::cout << "Tarefas iniciadas em background. Fazendo outro trabalho..." << std::endl;
    
    // Espera e obtém resultados de todas as tarefas
    int soma = 0;
    for (auto& tarefa : tarefas) {
        // .get() espera pela conclusão e retorna o resultado
        soma += tarefa.get();
    }
    
    auto fim = std::chrono::high_resolution_clock::now();
    auto duracao = std::chrono::duration_cast<std::chrono::seconds>(fim - inicio).count();
    
    std::cout << "Soma dos resultados: " << soma << std::endl;
    std::cout << "Tempo total: " << duracao << " segundos" << std::endl;
    
    return 0;
}
