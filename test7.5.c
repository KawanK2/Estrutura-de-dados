#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no* proximo;
}No;

typedef struct fila{
    No* ini;
    No* fim;
}Fila;

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

Fila* cria(void){
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

void entra(Fila* f, int v){
    No* novo_no = insere(f->fim, v);
    novo_no->proximo = NULL;
    if(f->fim != NULL){
        f->fim->proximo = novo_no;
    }
    f->fim = novo_no;
    if(f->ini == NULL){
        f->ini = f->fim;
    }
}

int vazia(Fila* f){
    return(f->ini == NULL);
}

int sai(Fila* f){
    int v;
    if(vazia(f)){
        printf("fila vazia.\n");
        exit(1);
    }
    v = f->ini->info;
    f->ini = retira(f->ini);
    if(f->ini == NULL){
        f->fim = NULL;
    }
    return v;
}

void imprime(Fila* f){
    No* q;
    for(q=f->ini;q != NULL; q = q->proximo){
        printf("%d\n", q->info);
    }
}

int main(){
    Fila* fila_normal = cria();
    Fila* fila_p = cria();
    int senha_normal = 1;
    int senha_p = 100;
    int op;
    int opw = 0;
    while(opw == 0){
        printf("Escolha uma das opções abaixo digitando seu respectivo número:\n1-Retirar senha\n2-Chamar próximo\n3-Mostrar filas\n4-Retirar senha prioritária\n");
        scanf("%d", &op);
        if(op == 1){
            entra(fila_normal, senha_normal);
            printf("Senha retirada: %d\n", senha_normal);
            senha_normal++;
        }else if(op == 2){
            if(vazia(fila_p) != NULL){
                printf("Senha chamada: %d\n", sai(fila_normal));
            }else{
                printf("Senha chamada: %d\n", sai(fila_p));
            }
        }else if (op == 3){
            printf("Fila normal atual:\n");
            imprime(fila_normal);
            printf("Fila prioritária atual:\n");
            imprime(fila_p);
        }else if(op == 4){
            entra(fila_p, senha_p);
            printf("Senha retirada: %d\n", senha_p);
            senha_p++;
        }
        else{
            printf("Opção não encontrada!!!\n");
        }
        printf("\nDeseja finalizar o programa\n0-Não\n1-Sim\n");
        scanf("%d", &opw);
        while(opw != 1 && opw != 0){
            printf("opção inválida, tente novamente");
            printf("\nDeseja finalizar o programa\n0-Não\n1-Sim\n");
            scanf("%d", &opw);
        }
    }
}
