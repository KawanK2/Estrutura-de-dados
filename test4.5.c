
#include <stdio.h>
#include <stdlib.h>

struct Aluno{
    int matricula;
    float nota;
};

int main(){
    int qtd;
    int i;
    
    printf("Digite a quantidade de alunos:\n");
    scanf("%d", &qtd);
    struct Aluno *alunos;
    alunos = (struct Aluno *) malloc(qtd * sizeof(struct Aluno));
    for (i=0;i<qtd;i++){
        printf("Digite a matrícula do aluno:");
        scanf("%d",&alunos[i].matricula);
        printf("Digite uma nota:");
        scanf("%f",&alunos[i].nota);
    };
    for(i=0;i<qtd;i++){
        printf("Matricula: %d - Nota: %.2f\n", alunos[i].matricula, alunos[i].nota);
    };
    
    free(alunos);
    return 0;
};
