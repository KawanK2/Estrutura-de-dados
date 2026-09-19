
#include <stdio.h>

int fatorial (int n){
    int fat = 1;
    int i;
    for(i=1;i<=n;i++){
        fat=fat*i;
    };
    return printf("Fatorial de %d = %d", n, fat);
};

int main(){
    fatorial(5);
};
