#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

const int PORT = 8080;
const int BUFFER_SIZE = 1024;

int main()
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    const char *response = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello, World!";

    // Criando o socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        std::cerr << "Erro ao criar o socket" << std::endl;
        return -1;
    }

    // Configurando o socket
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        std::cerr << "Erro ao configurar o socket" << std::endl;
        return -1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Vinculando o socket à porta
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        std::cerr << "Erro ao vincular o socket à porta" << std::endl;
        return -1;
    }

    // Escutando por conexões
    if (listen(server_fd, 3) < 0)
    {
        std::cerr << "Erro ao escutar por conexões" << std::endl;
        return -1;
    }

    std::cout << "Servidor escutando na porta " << PORT << "..." << std::endl;

    // Aceitando uma nova conexão
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
    {
        std::cerr << "Erro ao aceitar a conexão" << std::endl;
        return -1;
    }

    // Lendo a requisição do cliente
    read(new_socket, buffer, BUFFER_SIZE);
    std::cout << "Mensagem recebida: " << buffer << std::endl;

    // Enviando uma resposta ao cliente
    send(new_socket, response, strlen(response), 0);
    std::cout << "Resposta enviada" << std::endl;

    // Fechando o socket
    close(new_socket);
    close(server_fd);

    return 0;
}