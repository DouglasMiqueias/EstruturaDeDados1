#include<stdio.h>

/*
Escreva um programa que declare uma struct chamada Pessoa
com os campos nome (string de até 50 caracteres), idade
(inteiro) e altura (float). Leia os dados de uma pessoa
e exiba as informações armazenadas.
*/

struct Pessoa{
    char nome[50];
    int idade;
    double altura;
};
typedef struct Pessoa pessoa;

int main()
{

    pessoa p1;

    printf("Digite o nome da pessoa: \n");
    fgets(p1.nome, sizeof(p1.nome), stdin);
    // Usando o fgets para ler o nome com espaços


    p1.nome[strcspn(p1.nome, "\n")] = '\0';
    // Remove o \n do final, se existir

    printf("Digite a idade da pessoa: \n");
    scanf("%d", &p1.idade);

    printf("Digite a altura da pessoa: \n");
    scanf("%lf", &p1.altura);

    printf("\n== DADOS ==\n\n");
    printf("Nome da pessoa: %s\n", p1.nome);
    printf("Idade da pessoa: %d\n", p1.idade);
    printf("Altura da pessoa: %.2lf\n", p1.altura);

    return 0;
}
