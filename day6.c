#include <stdio.h>
int factorial(int n) {
    if (n <= 1) 
    { 
        return 1;
    } else
    {
        return n * factorial(n - 1); 
    }
}
int main() {
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    if (n < 0)
    {
        printf("the number is negative");
    } else
    {
        printf("Factorial of %d is %d\n", n, factorial(n));
    }
    return 0;
}