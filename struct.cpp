#include <stdio.h>
#include <string.h>
#include <locale.h>

// criando um novo tipo de dados
struct alunos
{
    int idade;
    float peso;
    char nome[50];
};
// redefine struct alunos para apenas alunos
typedef struct alunos alunos;

int main()
{
    //setando o UTF-8
    setlocale(LC_ALL, "Portuguese");

    //Criando uma variavel do tipo alunos  e inicializando
    alunos aluno1 = {0,0.0,"Teste"};

    printf("Início: \n");
    printf("alunos.idade: %d \n", aluno1.idade);
    printf("alunos.peso: %.2f \n", aluno1.peso);
    printf("alunos.nome: %s \n", aluno1.nome);

    //Atribuindo valores aos campos

    aluno1.idade = 12;
    aluno1.peso = 54.80;
    strcpy(aluno1.nome, "Texto");

    printf("\nAlterando os campos via código:\n");
    printf("alunos.idade: %d \n", aluno1.idade);
    printf("alunos.peso: %.2f \n", aluno1.peso);
    printf("alunos.nome: %s \n", aluno1.nome);

    //Solicitando inserções via teclado
    printf("\nInsira a idade do aluno:\n");
    scanf("%d", &aluno1.idade);
    printf("Insira o peso do aluno:\n");
    scanf("%f", &aluno1.peso);
    fflush(stdin);
    printf("Insira o nome do aluno:\n");
    scanf("%s", &aluno1.nome);


    printf("\nAlterando com dados inseridos pelo usuário:\n");
    printf("alunos.idade: %d \n", aluno1.idade);
    printf("alunos.peso: %.2f \n", aluno1.peso);
    printf("alunos.nome: %s \n", aluno1.nome);


    alunos aluno2 = {15, 70.50, "Ricardo"};

    printf("\nalunos.idade: %d \n", aluno2.idade);
    printf("alunos.peso: %.2f \n", aluno2.peso);
    printf("alunos.nome: %s \n", aluno2.nome);

    return 0;
}
