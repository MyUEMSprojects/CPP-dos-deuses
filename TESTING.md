# Testes automatizados em C++

Este repositório não traz uma suíte de testes completa de propósito — o objetivo aqui é ensinar C++, e encher o projeto de infraestrutura de teste ia atrapalhar mais do que ajudar. Em vez disso, este guia explica **como** fazer testes automatizados em C++ e traz um exemplo funcional mínimo em [`content/testing/`](content/testing/) que você pode copiar para o seu próprio projeto.

## Por que testar

Um teste automatizado é uma função que chama seu código com entradas conhecidas e verifica se a saída é a esperada — sem você precisar rodar o programa manualmente e olhar o `std::cout` toda vez. Isso importa porque:

- Você reexecuta os testes em segundos sempre que muda algo, em vez de testar tudo na mão de novo.
- Uma falha aponta exatamente qual comportamento quebrou, com arquivo e linha.
- Vira parte do CI: um PR com teste quebrado nem chega a ser mergeado.

## Nível 0: `assert` e `static_assert`

Antes de qualquer framework, o C++ já tem duas ferramentas embutidas:

```cpp
#include <cassert>

int square(int x) { return x * x; }

int main() {
    assert(square(3) == 9);   // checado em runtime; some em builds -DNDEBUG (release)
    static_assert(square(3) == 9); // checado em tempo de compilação (square precisa ser constexpr)
}
```

`assert` é útil para checagens rápidas durante o desenvolvimento, mas tem dois problemas como "suíte de testes": ele **aborta** o programa na primeira falha (você não vê as outras) e desaparece em builds de release (`NDEBUG`). Não serve pra validar comportamento de forma sistemática — serve pra invariantes internas.

## Nível 1: um framework mínimo (o que está em `content/testing/`)

Um framework de testes de verdade resolve os dois problemas acima:
1. Registra vários casos de teste e roda todos, mesmo que um falhe.
2. Reporta falhas sem abortar o processo (`CHECK` continua, ao contrário de `assert`).
3. Devolve um exit code (0 = passou, != 0 = falhou) para o CI decidir o resultado.

[`content/testing/mini_test.hpp`](content/testing/mini_test.hpp) implementa isso em ~50 linhas, só com `<functional>`, `<iostream>`, `<string>`, `<vector>` — nenhuma dependência externa. As peças:

- `TEST_CASE(nome) { ... }` declara uma função de teste e se auto-registra num vetor estático (usando o truque de um objeto `static` cujo construtor roda antes do `main`).
- `CHECK(expressao)` avalia a expressão; se for falsa, imprime o arquivo/linha e marca o teste atual como falho, mas **não** interrompe a execução.
- `TEST_MAIN()` gera o `main()` que roda todos os testes registrados e retorna o exit code certo.

Exemplo completo em [`content/testing/example_test.cpp`](content/testing/example_test.cpp), testando as funções de [`content/testing/math_utils.hpp`](content/testing/math_utils.hpp):

```cpp
#include "math_utils.hpp"
#include "mini_test.hpp"

TEST_CASE(gcd_basic_cases)
{
    CHECK(gcd(12, 18) == 6);
    CHECK(gcd(0, 5) == 5);
}

TEST_CASE(is_prime_detects_primes_and_non_primes)
{
    CHECK(is_prime(2));
    CHECK(!is_prime(1)); // 1 não é primo, por definição
}

TEST_MAIN()
```

Para rodar (o `Makefile` da raiz já sabe compilar e executar qualquer `.cpp` do repositório):

```bash
make example_test
```

Isso serve bem para arquivos avulsos, como os deste repositório, ou para projetos pequenos onde adicionar uma dependência externa não compensa. Para um projeto de verdade, prefira um framework estabelecido (próxima seção) — reinventar asserções e descoberta de testes não é um bom uso do seu tempo além do aprendizado.

## Nível 2: frameworks de verdade

Para projetos reais, use uma biblioteca de testes estabelecida em vez do framework mínimo acima. As três mais comuns:

### doctest — a mais leve

Um único header (`doctest.h`), zero dependências, compila rápido. Boa opção default quando você quer algo além do `mini_test.hpp` mas ainda simples de adicionar.

```cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("gcd calcula o máximo divisor comum") {
    CHECK(gcd(12, 18) == 6);
    CHECK(gcd(0, 5) == 5);
}
```

```bash
g++ -std=c++20 my_test.cpp -o my_test && ./my_test
```

### Catch2 — o mais popular para projetos médios

Também disponível como header único (versões mais antigas) ou como biblioteca via CMake/`FetchContent` (versão 3+). Sintaxe expressiva (`REQUIRE`, `SECTION` para organizar variações de um mesmo teste, matchers para mensagens de erro melhores).

```cpp
#include <catch2/catch_test_macros.hpp>

TEST_CASE("gcd calcula o máximo divisor comum") {
    SECTION("números coprimos") {
        REQUIRE(gcd(13, 17) == 1);
    }
    SECTION("um dos números é zero") {
        REQUIRE(gcd(0, 5) == 5);
    }
}
```

### GoogleTest (gtest) — o mais robusto, padrão em projetos grandes/empresas

Precisa ser compilado como biblioteca (via CMake é o caminho mais simples) e linkado ao seu executável de testes. Traz mocks (`gmock`), fixtures reutilizáveis (`TEST_F`) e integração pronta com quase todo CI.

```cpp
#include <gtest/gtest.h>

TEST(MathUtils, GcdBasicCases) {
    EXPECT_EQ(gcd(12, 18), 6);
    EXPECT_EQ(gcd(0, 5), 5);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

### Qual escolher

| Se você quer... | Use |
|---|---|
| Só entender a mecânica de um framework de teste | `content/testing/mini_test.hpp` deste repositório |
| Um header, zero fricção, projeto pequeno/médio | doctest |
| Sintaxe expressiva, BDD-style (`SECTION`, `GIVEN`/`WHEN`/`THEN`) | Catch2 |
| Mocks, fixtures complexas, é o padrão da sua empresa/equipe | GoogleTest |

## Boas práticas, independente do framework

- **Teste comportamento, não implementação.** Teste o que a função retorna para cada entrada relevante, não como ela calcula isso por dentro — senão todo refactor quebra os testes mesmo sem bug nenhum.
- **Um nome de teste descreve o cenário**, não a função: `gcd_returns_b_when_a_is_zero` é mais útil que `test_gcd_2`.
- **Cubra os casos de borda**: entrada vazia, zero, negativo, maior valor possível, string vazia — é onde bugs realmente moram.
- **Teste também os `throw`**: se uma função deve lançar uma exceção em certas condições, isso é parte do contrato dela e merece um teste (`REQUIRE_THROWS_AS` no Catch2, `EXPECT_THROW` no gtest, ou um `try/catch` manual no `mini_test.hpp`).
- **Testes rápidos e determinísticos.** Nada de `sleep()`, chamadas de rede ou dependência da hora do sistema num teste unitário — isso é teste de integração, e merece rodar separado.

## Integrando ao Makefile deste repositório

Qualquer arquivo `_test.cpp` (ou qualquer nome) dentro de `content/` ou `exercicies/` já funciona com `make <nome>`, como qualquer outro exemplo — não é preciso nenhuma configuração extra:

```bash
make example_test
```
