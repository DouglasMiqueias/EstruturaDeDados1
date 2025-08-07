#include<stdio.h>
#include<stdlib.h>

int main(){

    struct carro{
        int placa;
        int ano;
        int renavan;
    };
    typedef struct carro carro;
    carro car;

    printf("Digite a placa do veiculo: \n");
    scanf("%d", &car.placa);
    printf("Digite o ano do veiculo: \n");
    scanf("%d", &car.ano);
    printf("Digite o renavan do veiculo: \n");
    scanf("%d", &car.renavan);

    system("cls");

    printf("Placa do veiculo: %d\n", car.placa );
    printf("Ano do veiculo: %d\n", car.ano);
    printf("Renavan do veiculo: %d \n", car.ano);
    return 0;
}
