#include<stdio.h>


struct Pessoa{
    int id;
    int idade;
    char nome[50];
    char endereco[100];
    };
    typedef struct Pessoa pessoa;

    void imprimir()
    {
        printf("Nome: %s", p.nome);
        printf("Endereco: %s", p.endereco);
    }

    void ler()
    {
        scanf("%[^\n]%c", p.nome);
        fgets(p.endereco, sizeof(p.endereco),stdin);
    }

int main()
{
    pessoa p;

    p.ler();
    p.imprimir();

    return 0;
}
