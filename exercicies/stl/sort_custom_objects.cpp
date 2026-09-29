#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/*
. Ordenando objetos próprios com std::sort

    Dado um vetor de Employee (nome, departamento, salário), ordene por
    múltiplos critérios: primeiro por departamento (alfabético), depois
    por salário (decrescente) dentro de cada departamento. Tudo com um
    único std::sort e um comparador lambda, sem precisar sobrecarregar
    operator< na struct.
*/

struct Employee
{
    std::string name;
    std::string department;
    double salary;
};

int main()
{
    std::vector<Employee> employees = {
        {"Ana", "Engenharia", 9000},
        {"Bruno", "Vendas", 5000},
        {"Carla", "Engenharia", 12000},
        {"Diego", "Vendas", 7000},
        {"Elis", "Engenharia", 9000},
    };

    std::sort(employees.begin(), employees.end(), [](const Employee &a, const Employee &b)
              {
                  if (a.department != b.department)
                  {
                      return a.department < b.department;
                  }
                  return a.salary > b.salary;
              });

    for (const auto &employee : employees)
    {
        std::cout << employee.department << " | " << employee.name
                  << " | R$ " << employee.salary << "\n";
    }

    return 0;
}
