#include<stdio.h>
/*
Escreva um programa que declare uma struct chamada Aluno com os campos nome (string de até 50
caracteres) e nota (float). Em seguida, declare um vetor com 5 alunos, leia os dados do teclado e exiba o
nome e a nota de todos os alunos.

*/

struct Aluno{
    char nome[50];
    double nota;
};
typedef struct Aluno aluno;

int main()
{
    aluno alunos[4];

    for(int i = 0; i < 5; i++)
    {
        printf("Informe o nome do aluno: %d\n", i + 1);
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        alunnos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';


        printf("Informe a nota do aluno: %d\n", i+1);
        scanf("%d", &alunos[i].nota);
    }

    for(int i = 0; i < 5; i++)
    {
        printf("Nome do aluno %d: %s49\n", i + 1, alunos[i].nome);


        printf("Informe a nota do aluno: %d\n", i+1);
        scanf("%d", &alunos[i].nota);
    }




    return 0;
}
