#include <iostream>
#include <string>

// 1. Declaração e definição de funções
// Declaração (protótipo) da função
int soma(int a, int b);

// Definição da função
int soma(int a, int b)
{
    return a + b;
}

// 2. Parâmetros e valores de retorno
double media(double a, double b)
{
    return (a + b) / 2.0;
}

// 3. Sobrecarga de funções
int soma(int a, int b, int c)
{
    return a + b + c;
}

double soma(double a, double b)
{
    return a + b;
}

// 4. Funções inline
inline int quadrado(int x)
{
    return x * x;
}

// 5. Passagem de parâmetros por valor, referência e ponteiro
void incrementoPorValor(int x)
{
    x++;
}

void incrementoPorReferencia(int &x)
{
    x++;
}

void incrementoPorPonteiro(int *x)
{
    if (x)
    { // Verifica se o ponteiro não é nulo
        (*x)++;
    }
}

int main()
{
    // 1. Declaração e definição de funções
    std::cout << "Soma de 5 e 3: " << soma(5, 3) << "\n";

    // 2. Parâmetros e valores de retorno
    std::cout << "Média de 4.5 e 5.5: " << media(4.5, 5.5) << "\n";

    // 3. Sobrecarga de funções
    std::cout << "Soma de 1, 2 e 3: " << soma(1, 2, 3) << "\n";
    std::cout << "Soma de 2.5 e 3.5: " << soma(2.5, 3.5) << "\n";

    // 4. Funções inline
    std::cout << "Quadrado de 5: " << quadrado(5) << "\n";

    // 5. Passagem de parâmetros por valor, referência e ponteiro
    int valor = 10;

    incrementoPorValor(valor);
    std::cout << "Após incremento por valor: " << valor << "\n"; // Valor não muda

    incrementoPorReferencia(valor);
    std::cout << "Após incremento por referência: " << valor << "\n"; // Valor muda

    incrementoPorPonteiro(&valor);
    std::cout << "Após incremento por ponteiro: " << valor << "\n"; // Valor muda

    return 0;
}