#pragma once

// Pequena "biblioteca" sendo testada em example_test.cpp. Em um projeto
// real isso estaria em um .cpp separado com sua própria interface em .hpp;
// aqui fica tudo em um header só por simplicidade didática.

constexpr bool is_prime(int n)
{
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

constexpr int gcd(int a, int b)
{
    while (b != 0)
    {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a < 0 ? -a : a;
}
