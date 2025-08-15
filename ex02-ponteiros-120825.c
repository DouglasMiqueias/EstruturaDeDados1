#include<stdio.h>
/* Escreva um programa que contenha duas variáveis inteiras.
Compare seus endereços e exiba o maior nendereço.
*/
int main(){
    int b, a;
    int *ptrA = &a;
    int *ptrB = &b;

    printf("Valor do endereco de a: %p\n", ptrA);
    printf("Valor do endereco de b: %p\n", ptrB);

    if(ptrA > ptrB) printf("\nO endereco de A eh maior: %p\n", ptrA);
    else if(ptrB > ptrA) printf("\nO endereco de B eh maior endereco: %p\n", ptrB);
    else printf("Os enderecos sao iguais.\n");

    return 0;

}
