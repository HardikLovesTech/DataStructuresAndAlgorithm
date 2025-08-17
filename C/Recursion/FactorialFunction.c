#include <stdio.h>

int Factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * Factorial(n-1);
    }
}

int main() {
    int n = 5;
    int result = Factorial(n);
    printf("Factorial of %d is %d\n", n, result);
    return 0;
}
