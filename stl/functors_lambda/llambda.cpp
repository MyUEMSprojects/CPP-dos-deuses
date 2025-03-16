/*
[captura](parâmetros) -> tipo_retorno {
    // Corpo da função
}
*/

#include <iostream>
#include <vector>
#include <algorithm> // Para std::sort, std::for_each, etc.

// 1. Definindo um Functor (objeto função)
class Multiplicador
{
public:
    Multiplicador(int fator) : fator(fator) {}

    // Sobrecarregando o operador ()
    int operator()(int num) const
    {
        return num * fator;
    }

private:
    int fator; // Fator de multiplicação
};

int main()
{
    std::vector<int> numeros = {1, 2, 3, 4, 5};

    // 2. Usando um Functor com std::transform
    Multiplicador multiplicarPor2(2); // Functor que multiplica por 2
    std::vector<int> resultado(numeros.size());

    std::transform(numeros.begin(), numeros.end(), resultado.begin(), multiplicarPor2);

    std::cout << "Resultado do Functor (multiplicar por 2): ";
    for (int num : resultado)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // 3. Usando uma Lambda com std::transform
    int fator = 3;
    std::transform(numeros.begin(), numeros.end(), resultado.begin(), [fator](int num)
                   {
                       return num * fator; // Lambda que multiplica por 3
                   });

    std::cout << "Resultado da Lambda (multiplicar por 3): ";
    for (int num : resultado)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // 4. Usando uma Lambda com std::sort (ordenar em ordem decrescente)
    std::sort(numeros.begin(), numeros.end(), [](int a, int b)
              {
                  return a > b; // Critério de ordenação
              });

    std::cout << "Vetor ordenado (decrescente): ";
    for (int num : numeros)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // 5. Usando uma Lambda com std::for_each (imprimir elementos)
    std::cout << "Elementos do vetor: ";
    std::for_each(numeros.begin(), numeros.end(), [](int num)
                  { std::cout << num << " "; });
    std::cout << "\n";

    // 6. Captura de variáveis em Lambdas
    int offset = 10;
    std::cout << "Elementos do vetor somados com offset (" << offset << "): ";
    std::for_each(numeros.begin(), numeros.end(), [offset](int num)
                  { std::cout << num + offset << " "; });
    std::cout << "\n";

    return 0;
}