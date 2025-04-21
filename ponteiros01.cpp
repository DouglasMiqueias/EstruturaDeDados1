#include <stdio.h>
#include <stdlib.h>

void display(int var, int *ptr);
void update(int *p);

int main()
{
    int var = 15;
    int *ptr;

    ptr = &var;

    display(var, ptr);

    update(&var);
    display(var, ptr);

    printf("\n\nConteudo de var = %d\n", var);
    printf("Endereco de var = %p\n", &var);
    printf("Conteudo apontado por ptr = %d\n", *ptr);
    printf("Endereco apontado por = %p\n", ptr);
    printf("Endereco do ptr = %p\n", &ptr);

// *ptr : apontado por, conteudo do endereço da variavel que ptr aponta
// ptr:  enderço da variavel
// &ptr: endereço do ponteiro


    printf("\n\nEnd");
    while(1);
    return 0;
}
void display(int var, int *ptr)
{
    printf("\n\nConteudo de var = %d\n", var);
    printf("Endereco de var = %p\n", &var);
    printf("Conteudo apontado por ptr = %d\n", *ptr);
    printf("Endereco apontado por = %p\n", ptr);
    printf("Endereco do ptr = %p\n", &ptr);

}
void update(int *p)
{
    *p = *p+1;
}

