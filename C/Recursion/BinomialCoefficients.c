#include  <stdio.h>

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int Binomial(int n , int r){
        return (factorial(n)/(factorial(r)*factorial(n-r)));
}

// Function prototype for BinomialRecursive
int BinomialRecursive(int n, int r);

void main(){
    printf("Enter n and r: ");
    int n , r;
    scanf("%d %d", &n, &r);
    Binomial(n, r);
    printf("Binomial Coefficient C(%d, %d) = %d\n", n, r, BinomialRecursive(n, r));
    
    printf("\n");
    return;
}

int BinomialRecursive(int n, int r) {
    if (r == 0) {
        return 1;
    }
    if (n == r) {
        return 1;
    }
    if (r < 0 || r > n) {
        return 0; 
    }
    return (BinomialRecursive(n - 1, r - 1) + BinomialRecursive(n - 1, r));
}