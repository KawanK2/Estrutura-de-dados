#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no* proximo;
}No;

typedef struct pilha{
    No* topo;
} Pilha;

Pilha* cria(void){
    Pilha* nova_pilha = (Pilha*)malloc(sizeof(Pilha));
    nova_pilha->topo = NULL;
    return nova_pilha;
}

No* insere(No* lista, int num){
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->info = num;
    novo_no->proximo = lista;
    return novo_no;
}

void push(Pilha* p, int v){
    p->topo = insere(p->topo, v);
}

void imprime(Pilha* p){
    No* q;
    for(q = p->topo; q != NULL; q = q->proximo){
        printf("%d\n", q->info);
    }
}

int main()
{
    int number;
    int rep;
    int op;
    Pilha *p1 = cria();
    Pilha *p2 = cria();
    
    printf("Digite a quantidade de números nas pilhas: \n");
    scanf("%d", &rep);
    
    for(op = 0;op <= rep; op++){
        printf("Digite um número inteiro: \n");
        scanf("%d", &number);
        if(number % 2 == 0){
            push(p1, number);
        }else{
            push(p2, number);
        }
    }
    printf("\n Pilha de números pares: \n");
    imprime(p1);
    printf("\n Pilha de números impares: \n");
    imprime(p2);
    
}
