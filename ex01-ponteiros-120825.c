#include<stdio.h>

int main(){
    int a = 3;
    double b = 6.5;
    char c = 'D';

    int *ptrInt;
    double *ptrDouble;
    char *ptrChar;

    ptrInt = &a;
    ptrDouble = &b;
    ptrChar = &c;

    printf("Valor de a: %d\n", a);
    printf("Valor do apontamento: %d\n", *ptrInt);
    printf("Valor do endereço de a: %p\n", ptrInt);
    *ptrInt = 9;
    printf("Alterando o valor da variavel via ponteiro...\n");
    printf("Valor atualizado de a: %d\n\n", a);

    int opcao;
    printf("Digite 1 para continuar: ");
    scanf("%d", &opcao);

    if(opcao != 1) return 0;
    system("cls");


    printf("Valor de b: %.2lf\n", b);
    printf("Valor do apontamento: %.2lf\n", *ptrDouble);
    printf("Valor do endereço de b: %p\n\n", ptrDouble);
    *ptrDouble = 8.4;
    printf("Alterando o valor da variavel via ponteiro...\n");
    printf("Valor atualizado de b: %.2lf\n\n", b);

    printf("Digite 1 para continuar: ");
    scanf("%d", &opcao);

    if(opcao != 1) return 0;
    system("cls");

    printf("Valor de c: %c\n", c);
    printf("Valor do apontamento: %c\n", *ptrChar);
    printf("Valor do endereço de c: %p\n", ptrChar);
    *ptrChar = 'Z';
    printf("Alterando o valor da variavel via ponteiro...\n");
    printf("Valor atualizado de c: %c\n\n", c);
    printf("Finalizando...\n");

    return 0;
}
