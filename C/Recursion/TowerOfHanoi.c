#include <stdio.h>

int TowerOfHanoi(int n)
{
    if(n == 1){
        return 1;
    }
    else{
        return 2 * TowerOfHanoi(n - 1) + 1;
    }
}

int main(){
    int n;
    scanf("%d" , &n);
    return TowerOfHanoi(n);
}