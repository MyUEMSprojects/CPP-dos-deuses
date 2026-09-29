#include <iostream>
#include <fstream>
#include <stdexcept>

class File
{

public:
    // Constructor: abre o arquivo
    File(const std::string& file_name) {
        file_.open(file_name);
        if(!file_.is_open()) {
            throw std::runtime_error("Erro ao abrir o arquivo: " + file_name);
        }
        std::cout << "Arquivo aberto: " << file_name << "\n";
    }

    // Destrutor: fecha o arquivo
    ~File() {
        if(file_.is_open()) {
            file_.close();
            std::cout << "Arquivo fechado.\n";
        }
    }

    // Método para escrever dados no arquivo
    void write(const std::string& data) {
        if(!file_.is_open()) {
            throw std::runtime_error("Arquivo não esta aberto.");
        }
        file_ << data << "\n";
        std::cout << "Dados escritos" << data << "\n";
    }
private:
    std::ofstream file_; // Stream para o arquivo
};


int main()
{
    try
    {
        // Cria um objeto File (abre o arquivo)
        File file("exemplo.txt");

        // Escreva dados no arquivo
        file.write("Linha 1");
        file.write("Linha 2");

        // Simula uma exceção
        throw std::runtime_error("Erro simulado!");
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exceção capturada: " <<  e.what() << '\n';
    }

    return 0;
}
