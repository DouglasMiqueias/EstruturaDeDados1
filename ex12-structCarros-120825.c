#include <stdio.h>
#include <string.h>
#include <windows.h>

/*
Escreva um programa que declare uma struct Carro com os campos modelo e ano. Em seguida, leia os
dados de 6 carros e exiba os modelos com ano superior a 2015
*/

struct Carro{
    char modelo[50];
    int ano;
};
typedef struct Carro carro;

int main()
{
    carro carros[6];

    for(int i = 0; i < 6; i++)
    {
        printf("Digite o modelo do carro: \n");
        fgets(carros[i].modelo, sizeof(carros[i].modelo), stdin);
        carros[i].modelo[strcspn(carros[i].modelo, "\n")] = '\0';

        printf("Digite o ano do carro: \n");
        scanf("%d", &carros[i].ano);
        getchar();
    }

    printf("Carros cadastrados com sucesso!\n");

    Sleep(2000);
    system("cls");
    printf("\n===== CARROS CADASTRADOS ====\n");

    for(int i = 0; i < 6; i++)
    {

        printf("\nCarro %d\n", i+1);
        printf("Modelo: %s\n", carros[i].modelo);
        printf("Ano: %d\n", carros[i].ano);
    }

    printf("\nCarros com ano de fabricacao superior a 2015: \n");

    for(int i = 0; i < 6; i++)
    {
        if(carros[i].ano > 2015)
        {
            printf("\n%s (%d)", carros[i].modelo, carros[i].ano );
        }
    }


    return 0;
}
