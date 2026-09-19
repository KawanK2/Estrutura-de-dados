#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p;

    p = (int *) malloc(sizeof(int));

    if (p == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    printf("Digite um valor inteiro: ");
    scanf("%d", p);

    printf("Valor armazenado: %d\n", *p);
    printf("Endereco de memoria: %p\n", (void *)p);

    free(p);

    return 0;
    
    //falta ampliacao
}
