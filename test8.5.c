#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
    int matricula;
    float nota;
} Aluno;

typedef struct arv {
    Aluno info;
    struct arv* esq;
    struct arv* dir;
} Arv;

Arv* inicia() {
    return NULL;
}

int vazia(Arv* a) {
    return a == NULL;
}

Arv* cria(Aluno c, Arv* sae, Arv* sad) {
    Arv* p = (Arv*)malloc(sizeof(Arv));
    if (p == NULL) {
        printf("Erro de memoria!\n");
        exit(1);
    }
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    return p;
}

Arv* insere(Arv* a, Aluno x) {
    if (a == NULL) {
        return cria(x, NULL, NULL);
    }
    if (x.matricula < a->info.matricula) {
        a->esq = insere(a->esq, x);
    }
    else if (x.matricula > a->info.matricula) {
        a->dir = insere(a->dir, x);
    }
    return a;
}

Arv* busca(Arv* a, int matricula) {
    if (a == NULL) {
        return NULL;
    }
    if (matricula == a->info.matricula) {
        return a;
    }
    if (matricula < a->info.matricula) {
        return busca(a->esq, matricula);
    }
    return busca(a->dir, matricula);
}

Arv* menor(Arv* a) {
    while (a->esq != NULL) {
        a = a->esq;
    }
    return a;
}

Arv* retira(Arv* a, int matricula) {
    if (a == NULL) {
        return NULL;
    }
    if (matricula < a->info.matricula) {
        a->esq = retira(a->esq, matricula);
    }
    else if (matricula > a->info.matricula) {
        a->dir = retira(a->dir, matricula);
    }
    else {
        if (a->esq == NULL && a->dir == NULL) {
            free(a);
            return NULL;
        }
        if (a->esq == NULL) {
            Arv* aux = a->dir;
            free(a);
            return aux;
        }
        if (a->dir == NULL) {
            Arv* aux = a->esq;
            free(a);
            return aux;
        }
        Arv* aux = menor(a->dir);
        a->info = aux->info;
        a->dir = retira(a->dir,aux->info.matricula);
    }
    return a;
}

void imprime(Arv* a) {
    if (a != NULL) {
        imprime(a->esq);
        printf("Matricula: %d | Nota: %.2f\n",
            a->info.matricula,
            a->info.nota);
        imprime(a->dir);
    }
}


void libera(Arv* a) {
    if (a != NULL) {
        libera(a->esq);
        libera(a->dir);
        free(a);
    }
}

int main() {
    Arv* raiz = inicia();
    int op;
    int matricula;
    Aluno novo;
    Arv* encontrado;
    do {
        printf("\n===== SISTEMA DE ALUNOS =====\n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Buscar/Listar alunos\n");
        printf("3 - Atualizar nota\n");
        printf("4 - Remover aluno\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        if (scanf("%d", &op) != 1) {
            printf("Entrada invalida!\n");
            break;
        }
        switch (op) {
            // CREATE
            case 1:
                printf("Digite a matricula: ");
                scanf("%d", &novo.matricula);
                encontrado = busca(raiz,
                                   novo.matricula);
                if (encontrado != NULL) {
                    printf("Matricula ja cadastrada!\n");
                    break;
                }
                printf("Digite a nota: ");
                scanf("%f", &novo.nota);
                raiz = insere(raiz, novo);
                printf("Aluno cadastrado com sucesso!\n");
                break;
            case 2:
                printf("\n1 - Buscar aluno\n");
                printf("2 - Listar todos\n");
                printf("Escolha: ");
                int subop;
                scanf("%d", &subop);
                if (subop == 1) {
                    printf("Digite a matricula: ");
                    scanf("%d", &matricula);
                    encontrado = busca(raiz, matricula);
                    if (encontrado != NULL) {
                        printf("\nAluno encontrado!\n");
                        printf("Matricula: %d\n",
                            encontrado->info.matricula);
                        printf("Nota: %.2f\n",
                            encontrado->info.nota);
                    } else {
                        printf("Aluno nao encontrado!\n");
                    }
                }
                else if (subop == 2) {
                    if (vazia(raiz)) {
                        printf("Arvore vazia!\n");
                    } else {
                        printf("\nLista de alunos:\n");
                        imprime(raiz);
                    }
                }
                else {
                    printf("Opcao invalida!\n");
                }
                break;
            case 3:
                printf("Digite a matricula do aluno: ");
                scanf("%d", &matricula);
                encontrado = busca(raiz, matricula);
                if (encontrado != NULL) {
                    printf("Nota atual: %.2f\n",
                        encontrado->info.nota);
                    printf("Digite a nova nota: ");
                    scanf("%f", &encontrado->info.nota);
                    printf("Nota atualizada com sucesso!\n");
                } else {
                    printf("Aluno nao encontrado!\n");
                }
                break;
            case 4:
                printf("Digite a matricula para remover: ");
                scanf("%d", &matricula);
                encontrado = busca(raiz, matricula);
                if (encontrado != NULL) {
                    raiz = retira(raiz, matricula);
                    printf("Aluno removido com sucesso!\n");
                } else {
                    printf("Aluno nao encontrado!\n");
                }
                break;
            case 0:
                printf("Encerrando programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (op != 0);
    libera(raiz);
    return 0;
}
