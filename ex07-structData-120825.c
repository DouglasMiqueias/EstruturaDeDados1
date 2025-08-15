#include<stdio.h>
/*
Escreva um programa que declare uma struct chamada Data com
os campos dia, mês e ano, todos inteiros. Leia uma data do
teclado e exiba no formato dd/mm/aaaa.

*/

struct Data{
    int dia;
    int mes;
    int ano;

};
typedef struct Data data;

int main(){
    data d1;

    printf("Digite o dia: \n");
    scanf("%d", &d1.dia);

    printf("Digite o mes: \n");
    scanf("%d", &d1.mes);

    printf("Digite o ano: \n");
    scanf("%d", &d1.ano);

    printf("\nData formatada: %02d/%02d/%04d\n", d1.dia, d1.mes, d1.ano);

    // %02d para garantir que dia e mês tenham 2 dígitos
    //%04d para o ano, garantindo que apareça com 4 dígitos.

    return 0;
}
