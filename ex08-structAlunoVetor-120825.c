#include <stdio.h>
#include <string.h>

/*
Escreva um programa que declare um vetor de 3 elementos do tipo Aluno.
Leia os dados dos alunos pelo teclado e exiba o nome do aluno com a maior média.
*/

struct Aluno{
    char nome[50];
    int idade;
    double nota1, nota2;
};
typedef struct Aluno aluno;

int main()
{
    aluno alunos[3];

    for(int i = 0; i < 3; i++)
    {
        printf("Digite o nome do aluno %d: ", i+1);
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0'; // Remove \n do final

        printf("Digite a idade do aluno: ");
        scanf("%d", &alunos[i].idade);

        printf("Digite a nota da primeira avaliacao do aluno: ");
        scanf("%lf", &alunos[i].nota1);

        printf("Digite a nota da segunda avaliacao do aluno: ");
        scanf("%lf", &alunos[i].nota2);

        getchar(); // Limpa o \n que sobra no buffer após o scanf
    }

    int indiceMaior = 0;
    double maiorMedia = -1;

    for(int i = 0; i < 3; i++)
    {
        double media = (alunos[i].nota1 + alunos[i].nota2) / 2.0;

        if(media > maiorMedia)
        {
            maiorMedia = media;
            indiceMaior = i;
        }
    }

    printf("\nO aluno com a maior média é: %s (%.2lf)\n",
           alunos[indiceMaior].nome, maiorMedia);

    return 0;
}
