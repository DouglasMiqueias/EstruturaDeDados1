#include<stdio.h>
/*
Escreva um programa que leia dois valores inteiros e use
uma função com ponteiros para trocar os valores entre as
duas variáveis. Imprima os valores antes e depois da troca.
*/
void trocaValor(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int a, b;

    printf("Digite o valor de a: ");
    scanf("%d", &a);
    printf("Digite o valor de b: ");
    scanf("%d", &b);

    int *ptrA = &a;
    int *ptrB = &b;

    trocaValor(&a, &b);

    printf("\nDepois da troca:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    return 0;
}
