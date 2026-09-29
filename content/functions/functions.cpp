#include <iostream>
#include <string>

// 1. Declaração e definição de funções
// Declaração (protótipo) da função
int sum(int a, int b);

// Definição da função
int sum(int a, int b)
{
    return a + b;
}

// 2. Parâmetros e valores de retorno
double average(double a, double b)
{
    return (a + b) / 2.0;
}

// 3. Sobrecarga de funções
int sum(int a, int b, int c)
{
    return a + b + c;
}

double sum(double a, double b)
{
    return a + b;
}

// 4. Funções inline
inline int square(int x)
{
    return x * x;
}

// 5. Passagem de parâmetros por valor, referência e ponteiro
void incrementByValue(int x)
{
    x++;
}

void incrementByReference(int &x)
{
    x++;
}

void incrementByPointer(int *x)
{
    if (x)
    { // Verifica se o ponteiro não é nulo
        (*x)++;
    }
}

int main()
{
    // 1. Declaração e definição de funções
    std::cout << "Soma de 5 e 3: " << sum(5, 3) << "\n";

    // 2. Parâmetros e valores de retorno
    std::cout << "Média de 4.5 e 5.5: " << average(4.5, 5.5) << "\n";

    // 3. Sobrecarga de funções
    std::cout << "Soma de 1, 2 e 3: " << sum(1, 2, 3) << "\n";
    std::cout << "Soma de 2.5 e 3.5: " << sum(2.5, 3.5) << "\n";

    // 4. Funções inline
    std::cout << "Quadrado de 5: " << square(5) << "\n";

    // 5. Passagem de parâmetros por valor, referência e ponteiro
    int value = 10;

    incrementByValue(value);
    std::cout << "Após incremento por valor: " << value << "\n"; // Valor não muda

    incrementByReference(value);
    std::cout << "Após incremento por referência: " << value << "\n"; // Valor muda

    incrementByPointer(&value);
    std::cout << "Após incremento por ponteiro: " << value << "\n"; // Valor muda

    return 0;
}
