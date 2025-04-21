#include <stdio.h>
#include <locale.h>

void separarPartes(float numero, int *parteInteira, float *parteFracionaria)
{
    *parteInteira = (int)numero;  // Converte para inteiro (descarta a parte decimal)
    *parteFracionaria = numero - *parteInteira; // Parte fracionaria
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    float numero, fracao;
    int inteiro;

    puts("Digite um número real: ");
    scanf("%f", &numero);

    separarPartes(numero, &inteiro, &fracao);

    printf("Parte inteira %d\n", inteiro);
    printf("Parte fracionária: %.2lf\n", fracao);

    return 0;
}
