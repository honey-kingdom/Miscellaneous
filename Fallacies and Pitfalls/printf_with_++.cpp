#include <stdio.h>

int main()
{
    // This example shows an undefined behavior.
    volatile int a = 10;
    printf("\n %d %d", a, a++);

    a = 10;
    printf("\n %d %d", a++, a);

    a = 10;
    printf("\n %d %d %d ", a, a++, ++a);

    // It is not recommended Not to do two or more than two pre or post increment operators in the same statement.
}
