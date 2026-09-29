// Arquivo-modelo de teste automatizado. Veja TESTING.md na raiz do
// repositório para o guia completo. Rodar com:
//   make example_test

#include "math_utils.hpp"
#include "mini_test.hpp"

TEST_CASE(gcd_of_coprimes_is_one)
{
    CHECK(gcd(13, 17) == 1);
}

TEST_CASE(gcd_basic_cases)
{
    CHECK(gcd(12, 18) == 6);
    CHECK(gcd(0, 5) == 5);
    CHECK(gcd(48, 18) == 6);
}

TEST_CASE(is_prime_detects_primes_and_non_primes)
{
    CHECK(is_prime(2));
    CHECK(is_prime(17));
    CHECK(is_prime(97));
    CHECK(!is_prime(1));  // 1 não é primo, por definição
    CHECK(!is_prime(0));
    CHECK(!is_prime(15)); // 3 * 5
}

// Exemplo do que aconteceria com um teste que falha — descomente para ver
// o [ FAIL ] no relatório (e o exit code 1 no final):
//
// TEST_CASE(intentional_failure_example)
// {
//     CHECK(1 + 1 == 3); // propositalmente errado
// }

TEST_MAIN()
