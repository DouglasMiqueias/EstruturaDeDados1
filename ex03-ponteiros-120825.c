#include<stdio.h>

/*Escreva um programa que contenha duas vari�veis inteiras.
Leia essas vari�veis do teclado.
Em seguida, compare seus endere�os e exiba o conte�do
do maior endere�o.*/
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
