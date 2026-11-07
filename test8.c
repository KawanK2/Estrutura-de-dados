# include <stdio.h>
# include <stdlib.h>

typedef struct arv {
    int info;
    struct arv* esq;
    struct arv* dir;
}Arv;

int vazia(Arv* a) {
    return a == NULL;
}

Arv* inicia() {
    return NULL;
}

Arv* cria(int c, Arv* sae, Arv* sad) {
    Arv* p = (Arv*)malloc(sizeof(Arv));
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    return p;
}

void imprime(Arv* a) {
    if (!vazia(a)) {
        printf("%d ", a->info); /* mostra raiz */
        imprime(a->esq); /* mostra sae */
        imprime(a->dir); /* mostra sad */
    }
}

int pertence(Arv* a, int c){
    if(vazia(a)){
        return 0;
    }else{
        return 1;
    }
}

int conta_nos(Arv* a){
    if(a == NULL){
        return 0;
    }
    
    return 1 + conta_nos(a->esq) + conta_nos(a->dir);
}

int conta_folhas(Arv* a){
    if(a == NULL){
        return 0;
    }
    
    if(a->esq == NULL && a->dir == NULL){
        return 1;
    }
    
    return conta_folhas(a->esq) + conta_folhas(a->dir);
}

int main() {
    Arv* teste = cria(10, cria(5, cria(2, NULL, NULL), NULL), cria(20, NULL, cria(30, NULL, NULL)));
    
    printf("Árvore: \n");
    imprime(teste);
    printf("\n20 pertece a Ávore? %s\n", pertence(teste, 20) ? "sim" : "não");
    
    printf("Total de nós: %d\n", conta_nos(teste));
    
    printf("Total de folhas: %d\n", conta_folhas(teste));
}
