#include <stdio.h>

struct Aluno{
    int matricula;
    float nota;
};

int main(){
    int m;
    float n;
    int i;
    float media;
    struct Aluno alunos[5];
    for (i=0;i<=4;i++){
        printf("Digite a matrícula do aluno:");
        scanf("%d",&m);
        printf("Digite uma nota:");
        scanf("%f",&n);
        alunos[i].matricula = m;
        alunos[i].nota = n;
    };
    media = (alunos[0].nota + alunos[1].nota + alunos[2].nota + alunos[3].nota + alunos[4].nota) / 5;
    printf("Média da turma: %.2f\n", media);
    for (i=0;i<=4;i++){
        if(alunos[i].nota >= media){
            printf("Aluno aprovado: %d - Nota: %.2f\n", alunos[i].matricula, alunos[i].nota);
        };
    };
};
