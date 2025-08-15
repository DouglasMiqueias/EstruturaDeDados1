#include<stdio.h>
/*
Escreva um programa que declare uma struct Funcionario com os campos nome e salário. Em seguida,
leia os dados de 3 funcionários e exiba o nome do funcionário com o maior salário.
*/
struct funcionario{
    char nome[50];
    double salario;
};
typedef struct funcionario funcionario;

int main()
{
    funcionario funcionario[3];
    for(int i = 0; i < 3; i++)
    {
        printf("Digite o nome do funcionario: \n");
        fgets(funcionario[i].nome, sizeof(funcionario[i].nome), stdin);
        funcionario[i].nome[strcspn(funcionario[i].nome, "\n")] = '\0';

        printf("Digite o salario do funcionario: \n");
        scanf("%lf", &funcionario[i].salario);
        getchar();
    }

    double maior = funcionario[0].salario;
    int indice_maior = 0;

    for(int i = 0; i < 3; i++)
    {
        if(funcionario[i].salario > maior)
        {
            maior = funcionario[i].salario;
            indice_maior = i;
        }
    }

    printf("\nO funcionario com maior salario eh: %s (R$ %.2lf)\n",
           funcionario[indice_maior].nome, maior);

    return 0;
}
