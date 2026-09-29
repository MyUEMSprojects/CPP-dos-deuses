# CPP dos Deuses

Um projeto para treinar C++ avançado através de exemplos comentados e exercícios práticos, organizados por tópico.

## Requisitos

- Compilador com suporte completo a **C++20**, incluindo concepts, ranges e coroutines nativamente sob `-std=c++20` (sem flags experimentais). Testado com `g++ 13.3`; `g++ 11+` ou `clang++ 14+` também devem funcionar.
- Em `content/basic_network/server.cpp`: um sistema Linux/POSIX (usa `sys/socket.h`, `arpa/inet.h`)
- Nos exemplos com threads (`multithreading`, `async01`, `race_condition_fix`, `producer_consumer`, ...): linkagem com pthread (`-pthread`, já incluso no `Makefile`)

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

## Ordem de revisão sugerida

Se você já manja de C++ (sobrecarga de operadores, uma noção de smart pointers, etc.) e quer só revisar/preencher lacunas, não precisa seguir a ordem das tabelas abaixo — dá pra ir direto ao que interessa. Esta é uma trilha sugerida, dos fundamentos ao que costuma ser o ponto fraco de quem já programa em C++ há um tempo:

1. **Aquecimento rápido (só passar o olho, você já deve saber)**
   [`classes`](content/classes/classes.cpp) → [`diamond_problem`](content/classes/diamond_problem.cpp) → [`diamond_problem_solved`](content/classes/diamond_problem_solved.cpp) → [`bitwise`](content/bitwise/bitwise.cpp) → [`operator_overloading`](content/operator_overloading/operators.cpp) → [`functions`](content/functions/functions.cpp)
   Como você já domina sobrecarga de operadores, o ponto de atenção aqui é só o `diamond_problem_solved.cpp` (herança virtual) — o resto é revisão de 5 minutos.

2. **Gerenciamento de memória (aprofunde — é normalmente onde ficam as lacunas)**
   [`memory_management`](content/memory_management/management.cpp) → [`smart-pointers/unique_ptr`](content/memory_management/smart-pointers/unique_ptr.cpp) → [`smart-pointers/shared_ptr`](content/memory_management/smart-pointers/shared_ptr.cpp) → [`smart-pointers/weak_ptr`](content/memory_management/smart-pointers/weak_ptr.cpp) → [`move_semantics_and_rvalue_references`](content/move_semantics_and_rvalue_references/semantic_rvalue.cpp)
   Depois pratique em `exercicies/memory_management/` **nesta ordem**: `dinamic_alocation` → `matrix` → `unique_ptr` → `shared_ptr` → `unique_shared` → `customer_delete` (deleter customizado) → `evitar_ciclos` (o mais importante: `weak_ptr` quebrando ciclo de referência) → `raii` → `except_memory` → `leak` (esse último não libera memória de propósito — rode com `valgrind`/`AddressSanitizer` para *ver* o vazamento).

3. **Templates e genéricos**
   [`templates`](content/templates/templates.cpp) → `exercicies/templates/generic_stack.cpp` → `exercicies/templates/type_constraints.cpp` (já introduz concepts, adianta o passo 7).

4. **STL: revisão de nível 1** (você provavelmente já usa vector/map no dia a dia)
   [`stl/containers/sequential_containers`](content/stl/containers/sequential_containers/sequencial.cpp) → [`stl/containers/associative_containers`](content/stl/containers/associative_containers/associative.cpp) → [`stl/containers/unordered_containers`](content/stl/containers/unordered_containers/unordered.cpp) → [`stl/iterators`](content/stl/iterators/iterators.cpp) → [`stl/algorithims`](content/stl/algorithims/algorithms.cpp) → [`stl/functors_lambda`](content/stl/functors_lambda/llambda.cpp)
   Pratique com `exercicies/stl/word_frequency.cpp` e `exercicies/stl/sort_custom_objects.cpp`.

5. **Tratamento de exceções**
   [`exceptions`](content/exceptions/excptions.cpp) → `exercicies/exceptions/custom_exception_hierarchy.cpp` → `exercicies/exceptions/raii_exception_safety.cpp` (RAII + exceções é a combinação que mais aparece em código C++ real).

6. **Concorrência (costuma ser o próximo salto depois de "sei ponteiro inteligente")**
   [`multithreading_and_concorrência`](content/multithreading_and_concorrência/multithreading.cpp) → `exercicies/concurrency/race_condition_fix.cpp` (compile e rode **várias vezes** para ver o resultado não determinístico antes de ler a correção) → `exercicies/concurrency/producer_consumer.cpp` → [`async`](content/async/async01.cpp).

7. **C++20 "de verdade" (o mais recente do padrão, vale o maior investimento)**
   [`concepts`](content/concepts/concepts.cpp) → [`ranges`](content/ranges/ranges.cpp) → [`coroutines`](content/coroutines/coroutines.cpp) → volte para a seção 6 do [`modern_cpp`](content/modern_cpp/modern.cpp) (structured bindings, `if constexpr`, etc., o resto do arquivo é revisão de C++11/14/17).

8. **Design e arquitetura**
   [`design_patterns`](content/design_patterns/design.cpp) (SOLID, Singleton, Factory, Observer) → `exercicies/oop/shape_polymorphism.cpp` → `exercicies/oop/observer_pattern.cpp` (mesmo padrão do `design_patterns.cpp`, mas sem herança, com `std::function` — compare as duas abordagens) → [`coding_format`](content/coding_format/google.cpp) → [`documentation_Doxygen`](content/documentation_Doxygen/Doxygen.cpp).

9. **Extras (opcionais, conforme o interesse)**
   [`optimization`](content/optimization/optimization.cpp) (Big-O, profiling) → [`basic_network`](content/basic_network/server.cpp) (sockets POSIX) → [`TESTING.md`](TESTING.md) + [`content/testing/`](content/testing/) (como testar tudo isso de forma automatizada).

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
| **C++20 — concepts** (restrições de template, `requires`) | [content/concepts/concepts.cpp](content/concepts/concepts.cpp) |
| **C++20 — ranges** (`views::filter/transform/take`, pipelines com `\|`) | [content/ranges/ranges.cpp](content/ranges/ranges.cpp) |
| **C++20 — coroutines** (`co_yield`, gerador preguiçoso) | [content/coroutines/coroutines.cpp](content/coroutines/coroutines.cpp) |
| Testes automatizados: framework mínimo + exemplo | [content/testing/](content/testing/) — veja [TESTING.md](TESTING.md) |

### `exercicies/` — exercícios resolvidos

| Tópico | Exercício | Arquivo |
|---|---|---|
| Memória | Alocação dinâmica de array com validação de entrada | [exercicies/memory_management/dinamic_alocation.cpp](exercicies/memory_management/dinamic_alocation.cpp) |
| Memória | Alocação dinâmica de matriz (array 2D) | [exercicies/memory_management/matrix.cpp](exercicies/memory_management/matrix.cpp) |
| Memória | `unique_ptr` na prática | [exercicies/memory_management/unique_ptr.cpp](exercicies/memory_management/unique_ptr.cpp) |
| Memória | `shared_ptr` na prática | [exercicies/memory_management/shared_ptr.cpp](exercicies/memory_management/shared_ptr.cpp) |
| Memória | Combinando `unique_ptr` e `shared_ptr` | [exercicies/memory_management/unique_shared.cpp](exercicies/memory_management/unique_shared.cpp) |
| Memória | `shared_ptr` com deleter customizado | [exercicies/memory_management/customer_delete.cpp](exercicies/memory_management/customer_delete.cpp) |
| Memória | Evitando ciclos de referência com `weak_ptr` | [exercicies/memory_management/evitar_ciclos.cpp](exercicies/memory_management/evitar_ciclos.cpp) |
| Memória | RAII (Resource Acquisition Is Initialization) | [exercicies/memory_management/raii.cpp](exercicies/memory_management/raii.cpp) |
| Memória | Tratamento de exceções em código com alocação de memória | [exercicies/memory_management/except_memory.cpp](exercicies/memory_management/except_memory.cpp) |
| Memória | Exemplo de vazamento de memória (memory leak) | [exercicies/memory_management/leak.cpp](exercicies/memory_management/leak.cpp) |
| Templates | Pilha genérica (`Stack<T>`) | [exercicies/templates/generic_stack.cpp](exercicies/templates/generic_stack.cpp) |
| Templates | Restringindo tipos com concepts (`Numeric`) | [exercicies/templates/type_constraints.cpp](exercicies/templates/type_constraints.cpp) |
| Exceções | Hierarquia de exceções personalizadas | [exercicies/exceptions/custom_exception_hierarchy.cpp](exercicies/exceptions/custom_exception_hierarchy.cpp) |
| Exceções | Segurança contra exceções com RAII (rollback automático) | [exercicies/exceptions/raii_exception_safety.cpp](exercicies/exceptions/raii_exception_safety.cpp) |
| OOP | Polimorfismo com classes abstratas (`Shape`) | [exercicies/oop/shape_polymorphism.cpp](exercicies/oop/shape_polymorphism.cpp) |
| OOP | Padrão Observer com `std::function` | [exercicies/oop/observer_pattern.cpp](exercicies/oop/observer_pattern.cpp) |
| Concorrência | Race condition e como corrigi-la com `mutex` | [exercicies/concurrency/race_condition_fix.cpp](exercicies/concurrency/race_condition_fix.cpp) |
| Concorrência | Produtor-consumidor com `condition_variable` | [exercicies/concurrency/producer_consumer.cpp](exercicies/concurrency/producer_consumer.cpp) |
| STL | Contagem de frequência de palavras (`unordered_map` + `sort`) | [exercicies/stl/word_frequency.cpp](exercicies/stl/word_frequency.cpp) |
| STL | Ordenando objetos por múltiplos critérios | [exercicies/stl/sort_custom_objects.cpp](exercicies/stl/sort_custom_objects.cpp) |

## Testes automatizados

Este repositório não tem uma suíte de testes própria (ver motivo em [TESTING.md](TESTING.md)), mas traz um guia completo sobre como fazer testes automatizados em C++ — do `assert` básico até Catch2/doctest/GoogleTest — mais um framework mínimo funcional e comentado em [content/testing/](content/testing/). Experimente com:

```bash
make example_test
```

## Contribuindo

Sugestões e correções são bem-vindas. Ao adicionar um novo exemplo:

1. Crie uma pasta em `content/<tópico>/` (ou `exercicies/<tópico>/` para exercícios).
2. Garanta que o arquivo compila sem warnings com `-std=c++20 -Wall -Wextra`.
3. Nomes de variáveis, funções, classes e demais identificadores devem ser em **inglês** (`carEngine`, não `motorDoCarro`); comentários e mensagens exibidas ao usuário podem continuar em português, já que é o idioma do restante do repositório.
4. Atualize a tabela correspondente neste README.
