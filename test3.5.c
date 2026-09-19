#include <stdio.h>

void fatorial (int n){
    int fat = 1;
    int i;
    for(i=1;i<=n;i++){
        fat=fat*i;
    };
    printf("Fatorial de %d = %d", n, fat);
};

int main(){
    fatorial(5);
};
