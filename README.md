# CPP dos Deuses

Um projeto para treinar C++ avançado através de exemplos comentados e exercícios práticos, organizados por tópico.

## Requisitos

- Compilador com suporte a **C++20** (ex.: `g++` 10+ ou `clang++` 12+)
- Em `content/basic_network/server.cpp`: um sistema Linux/POSIX (usa `sys/socket.h`, `arpa/inet.h`)
- Em `content/multithreading_and_concorrência/multithreading.cpp` e `content/async/async01.cpp`: linkagem com pthread (`-pthread`)

## Como compilar e rodar um exemplo

O jeito mais rápido é usar o `Makefile` na raiz: basta digitar `make <nome_do_arquivo>` (sem o `.cpp`) que ele procura o arquivo em `content/` e `exercicies/`, compila e já executa:

```bash
make classes
make dinamic_alocation
```

O binário gerado fica em `build/<nome>` (pasta ignorada pelo git). Para limpar os binários:

```bash
make clean
```

Também é possível compilar manualmente qualquer arquivo `.cpp`, já que cada um é independente:

```bash
g++ -std=c++20 -Wall -Wextra -pthread content/classes/classes.cpp -o /tmp/classes
/tmp/classes
```

Para compilar rapidamente **todos** os exemplos e checar se algo quebrou:

```bash
find content exercicies -name "*.cpp" -print0 | \
  xargs -0 -I{} g++ -std=c++20 -Wall -Wextra -pthread -fsyntax-only {}
```

## Estrutura do repositório

```
content/      material de referência: um exemplo por tópico, comentado em português
exercicies/   exercícios resolvidos (atualmente focados em gerenciamento de memória)
```

### `content/` — tópicos cobertos

| Tópico | Arquivo |
|---|---|
| Classes, herança, polimorfismo, `friend` | [content/classes/classes.cpp](content/classes/classes.cpp) |
| Herança múltipla e o diamond problem | [content/classes/diamond_problem.cpp](content/classes/diamond_problem.cpp) |
| Diamond problem resolvido com herança virtual | [content/classes/diamond_problem_solved.cpp](content/classes/diamond_problem_solved.cpp) |
| Herança múltipla (exemplo adicional) | [content/classes/mult.cpp](content/classes/mult.cpp) |
| Operadores bit a bit (`&`, `\|`, `^`, `~`, `<<`, `>>`, flags) | [content/bitwise/bitwise.cpp](content/bitwise/bitwise.cpp) |
| Sobrecarga de operadores | [content/operator_overloading/operators.cpp](content/operator_overloading/operators.cpp) |
| Funções: parâmetros, sobrecarga, referências | [content/functions/functions.cpp](content/functions/functions.cpp) |
| Templates de função e de classe | [content/templates/templates.cpp](content/templates/templates.cpp) |
| Tratamento de exceções e exceções personalizadas | [content/exceptions/excptions.cpp](content/exceptions/excptions.cpp) |
| Gerenciamento de memória (RAII, new/delete) | [content/memory_management/management.cpp](content/memory_management/management.cpp) |
| Smart pointers: `unique_ptr` | [content/memory_management/smart-pointers/unique_ptr.cpp](content/memory_management/smart-pointers/unique_ptr.cpp) |
| Smart pointers: `shared_ptr` | [content/memory_management/smart-pointers/shared_ptr.cpp](content/memory_management/smart-pointers/shared_ptr.cpp) |
| Smart pointers: `weak_ptr` | [content/memory_management/smart-pointers/weak_ptr.cpp](content/memory_management/smart-pointers/weak_ptr.cpp) |
| Move semantics e rvalue references | [content/move_semantics_and_rvalue_references/semantic_rvalue.cpp](content/move_semantics_and_rvalue_references/semantic_rvalue.cpp) |
| Recursos modernos do C++ (C++11 em diante) | [content/modern_cpp/modern.cpp](content/modern_cpp/modern.cpp) |
| Padrões de projeto (Factory, Observer, etc.) | [content/design_patterns/design.cpp](content/design_patterns/design.cpp) |
| Multithreading e concorrência | [content/multithreading_and_concorrência/multithreading.cpp](content/multithreading_and_concorrência/multithreading.cpp) |
| Programação assíncrona (`std::async`, `std::future`) | [content/async/async01.cpp](content/async/async01.cpp) |
| Rede básica: servidor TCP com sockets POSIX | [content/basic_network/server.cpp](content/basic_network/server.cpp) |
| Otimização de código | [content/optimization/optimization.cpp](content/optimization/optimization.cpp) |
| Convenções de estilo (Google C++ Style Guide) | [content/coding_format/google.cpp](content/coding_format/google.cpp) |
| Documentação de código com Doxygen | [content/documentation_Doxygen/Doxygen.cpp](content/documentation_Doxygen/Doxygen.cpp) |
| **STL — containers sequenciais** (`vector`, `list`, `deque`, `array`, `forward_list`) | [content/stl/containers/sequential_containers/sequencial.cpp](content/stl/containers/sequential_containers/sequencial.cpp) |
| **STL — containers associativos** (`map`, `set`, ...) | [content/stl/containers/associative_containers/associative.cpp](content/stl/containers/associative_containers/associative.cpp) |
| **STL — containers não ordenados** (`unordered_map`, `unordered_set`) | [content/stl/containers/unordered_containers/unordered.cpp](content/stl/containers/unordered_containers/unordered.cpp) |
| **STL — algoritmos** (`sort`, `find`, `transform`, ...) | [content/stl/algorithims/algorithms.cpp](content/stl/algorithims/algorithms.cpp) |
| **STL — iteradores** | [content/stl/iterators/iterators.cpp](content/stl/iterators/iterators.cpp) |
| **STL — functors e lambdas** | [content/stl/functors_lambda/llambda.cpp](content/stl/functors_lambda/llambda.cpp) |

### `exercicies/memory_management/` — exercícios resolvidos

| Exercício | Arquivo |
|---|---|
| Alocação dinâmica de array com validação de entrada | [exercicies/memory_management/dinamic_alocation.cpp](exercicies/memory_management/dinamic_alocation.cpp) |
| Alocação dinâmica de matriz (array 2D) | [exercicies/memory_management/matrix.cpp](exercicies/memory_management/matrix.cpp) |
| `unique_ptr` na prática | [exercicies/memory_management/unique_ptr.cpp](exercicies/memory_management/unique_ptr.cpp) |
| `shared_ptr` na prática | [exercicies/memory_management/shared_ptr.cpp](exercicies/memory_management/shared_ptr.cpp) |
| Combinando `unique_ptr` e `shared_ptr` | [exercicies/memory_management/unique_shared.cpp](exercicies/memory_management/unique_shared.cpp) |
| `shared_ptr` com deleter customizado | [exercicies/memory_management/customer_delete.cpp](exercicies/memory_management/customer_delete.cpp) |
| Evitando ciclos de referência com `weak_ptr` | [exercicies/memory_management/evitar_ciclos.cpp](exercicies/memory_management/evitar_ciclos.cpp) |
| RAII (Resource Acquisition Is Initialization) | [exercicies/memory_management/raii.cpp](exercicies/memory_management/raii.cpp) |
| Tratamento de exceções em código com alocação de memória | [exercicies/memory_management/except_memory.cpp](exercicies/memory_management/except_memory.cpp) |
| Exemplo de vazamento de memória (memory leak) | [exercicies/memory_management/leak.cpp](exercicies/memory_management/leak.cpp) |

## Contribuindo

Sugestões e correções são bem-vindas. Ao adicionar um novo exemplo:

1. Crie uma pasta em `content/<tópico>/` (ou `exercicies/<tópico>/` para exercícios).
2. Garanta que o arquivo compila sem warnings com `-std=c++20 -Wall -Wextra`.
3. Atualize a tabela correspondente neste README.
