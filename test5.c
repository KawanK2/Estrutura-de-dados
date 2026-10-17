#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no* proximo;
}No;

No* inicia(){
    return NULL;
}

No* insere(No* lista, int num){
    No* novo_no;
    int tamanho=sizeof(No);
    
    novo_no = (No*) malloc(tamanho);
    novo_no->info=num;
    novo_no->proximo=lista;
    return novo_no;
}

No* busca(No* lista, int num){
    No* aux;
    for(aux=lista;aux!=NULL;aux=aux->proximo){
        if(aux->info==num){
            return aux;
        }
    }
    return NULL;
}

void imprime(No* lista){
    No* aux;
    for(aux=lista;aux!=NULL;aux=aux->proximo){
        printf("\nendereço alocado para lista %x conteudo %d proximo: %x", aux, aux->info, aux->proximo);
    }
}

No* retira(No* lista, int num){
    No* anterior = NULL;
    No* atual = lista;
    
    for(atual = lista;atual!=NULL;atual=atual->proximo){
        if(atual->info==num){
            break;
        }else{
            anterior=atual;
        }
    }
    if(atual==NULL){
        return lista;
    }
    if(anterior==NULL){
        lista=atual->proximo;
    }else{
        anterior->proximo=atual->proximo;
    }
    free(atual);
    return lista;
}

int main()
{
    No* lista1;
    lista1=inicia();
    printf("\nendereço alocado para lista %x conteudo %x", &lista1,lista1);
    
    No* novo_no;
    int tamanho = sizeof(No);
    novo_no = (No*) malloc (tamanho);
    
    novo_no->info=1;
    novo_no->proximo=lista1;
    
    lista1=novo_no;
    printf("\nendereço alocado para lista %x conteudo %d anterior: %x", lista1,lista1->info,lista1->proximo);
    
    novo_no = (No*) malloc (tamanho);
    novo_no->info=2;
    novo_no->proximo=lista1;
    
    lista1=novo_no;
    printf("\nendereço alocado para lista %x conteudo %d anterior: %x", lista1,lista1->info,lista1->proximo);
    
    novo_no = (No*) malloc (tamanho);
    novo_no->info=3;
    novo_no->proximo=lista1;
    
    lista1=novo_no;
    printf("\nendereço alocado para lista %x conteudo %d anterior: %x", lista1,lista1->info,lista1->proximo);
    
    novo_no = (No*) malloc (tamanho);
    novo_no->info=4;
    novo_no->proximo=lista1;
    
    lista1=novo_no;
    printf("\nendereço alocado para lista %x conteudo %d anterior: %x", lista1,lista1->info,lista1->proximo);
    
    imprime(lista1);
    
    No* lista2;
    lista2=inicia();
    printf("\nendereço alocado para lista %x conteudo %x", &lista2,lista2);
    
    novo_no = (No*) malloc (tamanho);
    novo_no->info=10;
    novo_no->proximo=lista2;
    
    lista2=novo_no;
    printf("\nendereço alocado para lista %x conteudo %d anterior: %x", lista2,lista2->info,lista2->proximo);
    
    novo_no = (No*) malloc (tamanho);
    novo_no->info=20;
    novo_no->proximo=lista2;
    
    lista2=novo_no;
    printf("\nendereço alocado para lista %x conteudo %d anterior: %x", lista2,lista2->info,lista2->proximo);
    
    novo_no = (No*) malloc (tamanho);
    novo_no->info=5;
    novo_no->proximo=lista1;
    
    lista1=novo_no;
    printf("\nendereço alocado para lista %x conteudo %d anterior: %x", lista1,lista1->info,lista1->proximo);
    
    novo_no = (No*) malloc (tamanho);
    novo_no->info=30;
    novo_no->proximo=lista2;
    
    lista2=novo_no;
    printf("\nendereço alocado para lista %x conteudo %d anterior: %x", lista2,lista2->info,lista2->proximo);
    
    novo_no = (No*) malloc (tamanho);
    novo_no->info=4;
    novo_no->proximo=lista1;
    
    lista1=novo_no;
    printf("\nendereço alocado para lista %x conteudo %d anterior: %x", lista1,lista1->info,lista1->proximo);
    
    novo_no = (No*) malloc (tamanho);
    novo_no->info=40;
    novo_no->proximo=lista2;
    
    lista2=novo_no;
    printf("\nendereço alocado para lista %x conteudo %d anterior: %x", lista2,lista2->info,lista2->proximo);
    
    imprime(lista1);
    imprime(lista2);
    
    return 0;
}

/*cria e inicia lista1;
 insere na lista1 1;
 insere na lista1 2;
 insere na lista1 3;
 insere na lista1 4;
 imprime a lista1;
 cria e inicia lista2;
 insere na lista2 10;
 insere na lista2 20;
 insere na lista1 5;
 insere na lista2 30;
 remove da lista1 4;
 insere na lista2 40;
 imprime a lista1;
 imprime a lista2;*/
