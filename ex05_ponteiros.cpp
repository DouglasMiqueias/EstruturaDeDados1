#include <stdio.h>

void encontrarMinMax(int vetor[], int tamanho, int *min, int *max)
{
    *min = *max = vetor[0]; // Começa assumindo o primeiro valor como mínimo e máximo

    for (int i = 1; i < tamanho; i++)
    {
        if (vetor[i] < *min)
            *min = vetor[i];

        if (vetor[i] > *max)
            *max = vetor[i];
    }
}

int main()
{
    int numeros[] = {7, 2, 15, 8, -3, 20, 1};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);
    int menor, maior;

    encontrarMinMax(numeros, tamanho, &menor, &maior);

    printf("Menor valor: %d\n", menor);
    printf("Maior valor: %d\n", maior);

    return 0;
}
