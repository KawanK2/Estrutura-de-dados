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

No* retira(No* lista){
    No* aux = lista;
    lista = aux->proximo;
    free(aux);
    return lista;
}

int vazia(Pilha* p){
    return(p->topo == NULL);
}

int pop(Pilha* p){
    int v;
    if(vazia(p)){
        printf("Pilha vazia.\n");
        exit(1);
    }
    v = p->topo->info;
    p->topo = retira(p->topo);
    return v;
}

void push(Pilha* p, int v){
    p->topo = insere(p->topo, v);
}

void imprime(Pilha* p){
    while(!vazia(p)){
        printf("%d", pop(p));
    }
    printf("\n");
}

int main()
{
    int number;
    int resto;
    Pilha *p1 = cria();
    printf("Digite um número inteiro:\n");
    scanf("%d",&number);
    
    while(number > 0){
        resto = number % 2;
        number = number /2;
        push(p1, resto);
    }
    
    
    
    imprime(p1);
}
