#include<stdio.h>
#include <windows.h> // Sleep
#include<string.h>

/*
Escreva um programa que declare uma struct chamada Endereco com os campos rua, número e cidade.
Leia os dados de dois endereços e determine se pertencem à mesma cidade.

*/

struct Endereco{
    char rua[50];
    char cidade[50];
    int numero;
};
typedef struct Endereco endereco;

int main()
{
    endereco end1;
    endereco end2;

    printf("Digite a rua do endereco 1: ");
    fgets(end1.rua, sizeof(end1.rua), stdin);
    end1.rua[strcspn(end1.rua, "\n")] = '\0';


    printf("Digite a cidade do endereco 1: ");
    fgets(end1.cidade, sizeof(end1.cidade), stdin);
    end1.cidade[strcspn(end1.cidade, "\n")] = '\0';


    printf("Digite o numero do endereco 1: ");
    scanf("%d", &end1.numero);

    while(getchar() != '\n'); // limpa buffer, pois o \n atrapalha na proxima leitura;


    printf("\nDados do endereco 1 preenchidos com sucesso!");

    Sleep(2000);
    system("cls");

    printf("Digite a rua do endereco 2: ");
    fgets(end2.rua, sizeof(end2.rua), stdin);
    end2.rua[strcspn(end2.rua, "\n")] = '\0';

    printf("Digite a cidade do endereco 2: ");
    fgets(end2.cidade, sizeof(end2.cidade), stdin);
    end2.cidade[strcspn(end2.cidade, "\n")] = '\0';

    printf("Digite o numero do endereco 2: ");
    scanf("%d", &end2.numero);

    printf("\nDados do endereco 2 preenchidos com sucesso!\n\n");

    Sleep(2000);
    system("cls");

    printf("Comparando se enderecos pertencem a mesma cidade...\n");

    /*
   ===================== PRIMEIRA TENTATIVA ===========================
    if(end1.cidade == end2.cidade) printf("\nOs enderecos pertencem a mesma cidade\n");
    else printf("\nOs enderecos sao de cidades diferentes\n");
    */

    if(strcmp(end1.cidade, end2.cidade) == 0)
        printf("\nOs enderecos pertencem a mesma cidade");
    else
        printf("\nOs enderecos sao de cidades diferentes");

    /*
        ============================= STRCMP ==============================
                strcmp vem da biblioteca <string.h> e serve para comparar duas strings em C, caractere por caractere.
        A função retorna:

        0 → as strings são iguais

        < 0 → a primeira string é “menor” (lexicograficamente) que a segunda

        > 0 → a primeira string é “maior” que a segunda
    */

    return 0;
}
