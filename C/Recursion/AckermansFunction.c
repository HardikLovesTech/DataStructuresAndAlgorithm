#include <stdio.h>

int AckermanFn(int m , int n){
    if (m == 0){
        return n+1;
    }
    if (n == 0){
        return AckermanFn(m - 1, 1);
    }
    
    return AckermanFn(m - 1, AckermanFn(m, n - 1));
}

int main(){
    int m, n;
    printf("Gimme input: ");
    scanf("%d %d", &m, &n);
    
    int result = AckermanFn(m, n);
    
    printf("%d\n", result);
    return 0;
}
