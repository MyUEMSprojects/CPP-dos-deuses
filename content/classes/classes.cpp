#include <iostream>
#include <string>

// 1. Definição de classes e objetos
class Carro
{
private:
    // 2. Membros de classe (atributos e métodos)
    std::string marca;
    std::string modelo;
    int ano;

public:
    // 3. Construtores e destrutores
    // Construtor padrão
    Carro() : marca("Desconhecida"), modelo("Desconhecido"), ano(0) {}

    // Construtor parametrizado
    Carro(const std::string &marca, const std::string &modelo, int ano)
        : marca(marca), modelo(modelo), ano(ano) {}

    // Destrutor
    ~Carro()
    {
        std::cout << "Destruindo o carro: " << marca << " " << modelo << "\n";
    }

    // Métodos públicos
    void exibirDetalhes() const
    {
        std::cout << "Marca: " << marca << ", Modelo: " << modelo << ", Ano: " << ano << "\n";
    }

    // 4. Modificadores de acesso (getters e setters)
    void setMarca(const std::string &marca)
    {
        this->marca = marca;
    }

    std::string getMarca() const
    {
        return marca;
    }

    void setModelo(const std::string &modelo)
    {
        this->modelo = modelo;
    }

    std::string getModelo() const
    {
        return modelo;
    }

    void setAno(int ano)
    {
        this->ano = ano;
    }

    int getAno() const
    {
        return ano;
    }

    // 6. Função amiga (friend)
    friend void exibirInformacoesPrivadas(const Carro &carro);
};

// 6. Função amiga (friend)
void exibirInformacoesPrivadas(const Carro &carro)
{
    std::cout << "Informações privadas (friend): " << carro.marca << " " << carro.modelo << " " << carro.ano << "\n";
}

// 5. Encapsulamento, herança e polimorfismo
class CarroEsportivo : public Carro
{
private:
    int velocidadeMaxima;

public:
    // Construtor
    CarroEsportivo(const std::string &marca, const std::string &modelo, int ano, int velocidadeMaxima)
        : Carro(marca, modelo, ano), velocidadeMaxima(velocidadeMaxima) {}

    // Polimorfismo: Sobrescrevendo um método da classe base
    void exibirDetalhes() const
    {
        Carro::exibirDetalhes(); // Chama o método da classe base
        std::cout << "Velocidade Máxima: " << velocidadeMaxima << " km/h\n";
    }
};

int main()
{
    // 1. Definição de classes e objetos
    Carro carro1; // Usando o construtor padrão
    carro1.setMarca("Toyota");
    carro1.setModelo("Corolla");
    carro1.setAno(2020);

    Carro carro2("Ford", "Mustang", 1967); // Usando o construtor parametrizado

    // 2. Membros de classe (atributos e métodos)
    std::cout << "Detalhes do carro1:\n";
    carro1.exibirDetalhes();

    std::cout << "Detalhes do carro2:\n";
    carro2.exibirDetalhes();

    // 4. Modificadores de acesso (getters e setters)
    carro1.setAno(2021);
    std::cout << "Novo ano do carro1: " << carro1.getAno() << "\n";

    // 6. Função amiga (friend)
    exibirInformacoesPrivadas(carro2);

    // 5. Encapsulamento, herança e polimorfismo
    CarroEsportivo carroEsportivo("Ferrari", "488 GTB", 2022, 330);
    std::cout << "Detalhes do carro esportivo:\n";
    carroEsportivo.exibirDetalhes();

    return 0;
}