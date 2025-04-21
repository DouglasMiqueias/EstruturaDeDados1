#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

#define TAM 3

// criando um novo tipo de dados
struct tipo_pessoa
{
    int idade;
    float peso;
    char nome[TAM];
};

typedef struct tipo_pessoa tipo_pessoa;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    tipo_pessoa lista[3];

    for(int i = 0; i < TAM; i++)
    {
        printf("Insira os dados (%d): \n", i+1);
        puts("Nome: ");
        scanf("%50[^\n]s", &lista[i].nome);
        fflush(stdin);

        puts("Idade: ");
        scanf("%d", &lista[i].idade);
        fflush(stdin);

        puts("Peso: ");
        scanf("%f", &lista[i].peso);
        fflush(stdin);
    }
    // limpar a tela
    system("cls");
    puts("Seus dados:\n");
    for(int i = 0; i < TAM; i++)
    {
        printf("------------------ Pessoa %d ------------------\n", i+1);
        printf("\tNome: %s\n", lista[i].nome);
        printf("\tIdade: %d\n", lista[i].idade);
        printf("\tPeso: %2f\n", lista[i].peso);
    }
    printf("----------------------------------------------\n");

}
