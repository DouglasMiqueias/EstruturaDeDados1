#include<stdio.h>

/*
Escreva um programa que declare uma variável inteira e um
ponteiro para inteiro. Leia um valor doteclado e armazene-o
usando o ponteiro. Em seguida, exiba o valor armazenado e o
endereço davariável.
*/

int main(){
    int a;
    int *ptrA;

    ptrA = &a;

    printf("Defina o valor de A: ");
    scanf("%d\n", &a);

    printf("Valor do apontamento: %d\n", *ptrA);
    printf("Valor do endereco da variavel: %p", ptrA);

    return 0;
}
