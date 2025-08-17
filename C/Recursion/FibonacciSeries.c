#include  <stdio.h>
int fibonacci(int n){

    int n0 = 0, n1 = 1, n2, i;
    if (n == 0)
        return n0;
    else if (n == 1)
        return n1;
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);

    }
}
    

void main(){
    int n, i;
    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");
    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    return;
}