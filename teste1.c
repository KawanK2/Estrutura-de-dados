
#include <stdio.h>

int main(){
    float n1, n2;
    float total;
    int operacao;

    printf("Digite um número:");
    scanf("%f", &n1);
    printf("Digite outro número:");
    scanf("%f",&n2);
    printf("Escolha a operação: 0 = Soma; 1 = Subtração; 2 = Multiplicação; 3 = Divisão");
    scanf("%d",&operacao);
    
    switch (operacao){
        case 0:
            total = n1 + n2;
            printf("Resultado: %f", total);
            break;
        case 1:
            total = n1 - n2;
            printf("Resultado: %f", total);
            break;
        case 2:
            total = n1 * n2;
            printf("Resultado: %f", total);
            break;
        case 3:
            total = n1 / n2;
            printf("Resultado: %f", total);
            break;
    };
};
