#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
    int matricula;
    float nota;
}Aluno;

typedef struct no{
    Aluno info;
    struct no *proximo;
}No;

No* inicia(){
    return NULL;
}

No* insere(No* lista, Aluno dados_aluno){
    No* novo_no;
    int tamanho=sizeof(No);
    
    novo_no = (No*) malloc(tamanho);
    novo_no->info.matricula=dados_aluno.matricula;
    novo_no->info.nota=dados_aluno.nota;
    novo_no->proximo=lista;
    return novo_no;
}

No* busca(No* lista, int matricula){
    No* aux;
    for(aux=lista;aux!=NULL;aux=aux->proximo){
        if(aux->info.matricula==matricula){
            return aux;
        }
    }
    return NULL;
}

void imprime(No* lista){
    No* aux;
    for(aux=lista;aux!=NULL;aux=aux->proximo){
        printf("\nendereço alocado para lista %x Matricula: %d Nota: %2.2f", aux, aux->info.matricula, aux->info.nota);
    }
}

No* retira(No* lista, int matricula){
    No* anterior = NULL;
    No* atual = lista;
    
    for(atual = lista;atual!=NULL;atual=atual->proximo){
        if(atual->info.matricula==matricula){
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
    No* salaLista;
    No* pesquisa;
    salaLista=inicia();
    
    No* novo_no;
    int tamanho = sizeof(No);
    
    novo_no = (No*) malloc (tamanho);
    novo_no->info.matricula=1;
    novo_no->info.nota=5.5;
    novo_no->proximo=salaLista;
    
    salaLista=novo_no;
    printf("\naluno alocado a sala: %x - matrícula: %d - nota: %2.2f", salaLista,salaLista->info.matricula, salaLista->info.nota);
    
    novo_no = (No*) malloc (tamanho);
    novo_no->info.matricula=2;
    novo_no->info.nota=7.5;
    novo_no->proximo=salaLista;
    
    salaLista=novo_no;
    printf("\naluno alocado a sala: %x - matrícula: %d - nota: %2.2f", salaLista,salaLista->info.matricula, salaLista->info.nota);
    
    novo_no = (No*) malloc (tamanho);
    novo_no->info.matricula=3;
    novo_no->info.nota=10.0;
    novo_no->proximo=salaLista;
    
    salaLista=novo_no;
    printf("\naluno alocado a sala: %x - matrícula: %d - nota: %2.2f", salaLista,salaLista->info.matricula, salaLista->info.nota);
    
    novo_no = (No*) malloc (tamanho);
    novo_no->info.matricula=4;
    novo_no->info.nota=1.0;
    novo_no->proximo=salaLista;
    
    salaLista=novo_no;
    printf("\naluno alocado a sala: %x - matrícula: %d - nota: %2.2f", salaLista,salaLista->info.matricula, salaLista->info.nota);
    
    novo_no = (No*) malloc (tamanho);
    novo_no->info.matricula=5;
    novo_no->info.nota=6.0;
    novo_no->proximo=salaLista;
    
    salaLista=novo_no;
    printf("\naluno alocado a sala: %x - matrícula: %d - nota: %2.2f", salaLista,salaLista->info.matricula, salaLista->info.nota);
    
    pesquisa = busca(salaLista, 3);
    
    if(pesquisa!=NULL){
        printf("\nAluno matrícula 3 - Nota: %2.2f", pesquisa->info.nota);
    }else{
        printf("Não encontrado");
    }
    
    salaLista = retira(salaLista, 3);
    
    imprime(salaLista);
    
    return 0;
}
