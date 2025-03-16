#include <iostream>
#include <fstream>
#include <stdexcept>

class Arquivo
{

public:
    // Constructor: abre o arquivo
    Arquivo(const std::string& nome_arquivo) {
        arquivo_.open(nome_arquivo);
        if(!arquivo_.is_open()) {
            throw std::runtime_error("Erro ao abrir o arquivo: " + nome_arquivo);
        }
        std::cout << "Arquivo aberto: " << nome_arquivo << "\n";
    }

    // Destrutor: fecha o arquivo
    ~Arquivo() {
        if(arquivo_.is_open()) {
            arquivo_.close();
            std::cout << "Arquivo fechado.\n";
        }
    }

    // Método para escrever dados no arquivo
    void escrever(const std::string& dados) {
        if(!arquivo_.is_open()) {
            throw std::runtime_error("Arquivo não esta aberto.");
        }
        arquivo_ << dados << "\n";
        std::cout << "Dados escritos" << dados << "\n";
    }
private:
    std::ofstream arquivo_; // Stream para o arquivo
};


int main()
{
    try
    {
        // Cria um Objeto Arquivo (abre o arquivo)
        Arquivo arquivo("exemplo.txt");

        // Escreva dados no arquivo
        arquivo.escrever("Linha 1");
        arquivo.escrever("Linha 2");

        // Simula uma execação
        throw std::runtime_error("Erro simulado!");
    }
    catch(const std::exception& e)
    {
        std::cerr << "Execação capturada: " <<  e.what() << '\n';
    }
    
    return 0;
}