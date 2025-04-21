#include <stdio.h>
#include <math.h>
#define PI 3.14159

void calcularEsfera(double raio, double *area, double *volume)
{
    *area = 4 * PI * pow(raio, 2);
    *volume = (4.0 / 3.0) * PI * pow(raio, 3);
}

int main()
{
    double raio, area, volume;

    printf("Digite o raio da esfera: ");
    scanf("%lf", &raio);

    calcularEsfera(raio, &area, &volume);

    printf("Área da superfície: %.2lf\n", area);
    printf("Volume da esfera: %.2lf\n", volume);

    return 0;
}
