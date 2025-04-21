#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    float numeros[10];

    for(int i = 0; i < 10; i++)
    {
        printf("Endereço do elemento numeros [%d]: %p\n", i, (void*)&numeros[i]);
    }


    return 0;
}
/*
(void*) → é um type cast para void*, que é o tipo esperado por %p no printf.
Sem isso, o compilador pode exibir um warning (aviso),
porque %p exige especificamente
um ponteiro genérico.
*/
