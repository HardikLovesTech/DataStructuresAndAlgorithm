#include <stdio.h>

struct Marks{
    int total;
    int sub[3];
};

int main()
{
    struct Marks Students[3] =  {{0 , 45 , 30 , 12} , {0 , 45 , 12 , 3} , {0 , 45 , 99 , 74}};
    return 0;
    int i , j;
    for(i = 0 ; i < 3 ; i++){
        for (int i = 0; i < 3; j++)
        {
            Students[i].total += Students[i].sub[j];
        }
        
    }
}
