#include<stdio.h>;

int main(){
    int a = 5, b = 7;
    int *ptr1, *ptr2;

    ptr1 = &a;
    ptr2 = &b;

    printf("Valor antigo de a: %d\n", a);
    printf("Valor antigo de b: %d\n", b);

    *ptr1 = 7;
    *ptr2 = 8;

    printf("Valor atual de a: %d\n", a);
    printf("Valor atual de b: %d\n", b);



    return 0;
}
