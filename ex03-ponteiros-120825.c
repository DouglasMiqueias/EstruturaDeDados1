#include<stdio.h>

/*Escreva um programa que contenha duas variáveis inteiras.
Leia essas variáveis do teclado.
Em seguida, compare seus endereços e exiba o conteúdo
do maior endereço.*/
int main(){
    int a, b;
    int *ptrA, *ptrB;

    ptrA = &a;
    ptrB = &b;

    printf("Digite o valor de A: ");
    scanf("%d", &a);

    printf("Digite o valor de B: ");
    scanf("%d", &b);

    if(ptrA > ptrB) printf("\nO endereco de A eh maior: %p\n", ptrA);
    else if(ptrB > ptrA) printf("\nO endereco de B eh maior endereco: %p\n", ptrB);
    else printf("Os enderecos sao iguais.\n");

    return 0;
}
