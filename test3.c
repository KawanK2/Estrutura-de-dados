
#include <stdio.h>

int fatorial (int n){
    int fat = 1;
    int i;
    for(i=1;i<=n;i++){
        fat=fat*i;
    };
    return fat;
};

int main(){
    fatorial(5);
};
