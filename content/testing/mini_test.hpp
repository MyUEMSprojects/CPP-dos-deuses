#pragma once

// Framework de testes minimalista (~50 linhas), sem dependências externas.
// Serve para exemplificar a MECÂNICA de um framework de testes (registro de
// casos, macros de asserção, relatório final). Veja TESTING.md na raiz do
// repositório para quando faz sentido trocar isso por Catch2/doctest/GoogleTest.

#include <functional>
#include <iostream>
#include <string>
#include <vector>

namespace mini_test
{

struct TestCase
{
    std::string name;
    std::function<void()> fn;
};

inline std::vector<TestCase> &registry()
{
    static std::vector<TestCase> tests;
    return tests;
}

struct Registrar
{
    Registrar(const std::string &name, std::function<void()> fn)
    {
        registry().push_back({name, std::move(fn)});
    }
};

inline int &currentTestFailures()
{
    static int count = 0;
    return count;
}

inline void reportCheck(bool ok, const char *expr, const char *file, int line)
{
    if (!ok)
    {
        std::cerr << "    FALHOU: CHECK(" << expr << ") em " << file << ":" << line << "\n";
        ++currentTestFailures();
    }
}

inline int runAll()
{
    int failedTests = 0;
    for (auto &test : registry())
    {
        currentTestFailures() = 0;
        std::cout << "[ RUN  ] " << test.name << "\n";
        test.fn();
        if (currentTestFailures() == 0)
        {
            std::cout << "[  OK  ] " << test.name << "\n";
        }
        else
        {
            std::cout << "[ FAIL ] " << test.name << "\n";
            ++failedTests;
        }
    }

    std::size_t total = registry().size();
    std::cout << "\n" << (total - failedTests) << "/" << total << " testes passaram.\n";
    return failedTests == 0 ? 0 : 1;
}

} // namespace mini_test

// Declara e registra um caso de teste. Uso:
//   TEST_CASE(soma_funciona) { CHECK(2 + 2 == 4); }
#define TEST_CASE(test_name)                                                    \
    void test_name();                                                          \
    static mini_test::Registrar registrar_##test_name(#test_name, test_name);  \
    void test_name()

// Verifica uma condição. Ao contrário de assert(), NÃO aborta o programa:
// registra a falha e o teste continua, para que todas as CHECKs de um
// mesmo teste sejam reportadas de uma vez, não só a primeira.
#define CHECK(expr) mini_test::reportCheck((expr), #expr, __FILE__, __LINE__)

// Gera o main() que executa todos os testes registrados e retorna o
// exit code apropriado (0 = tudo passou, 1 = alguma falha) — importante
// para integrar com CI, que decide sucesso/falha pelo exit code.
#define TEST_MAIN()               \
    int main()                    \
    {                              \
        return mini_test::runAll(); \
    }
