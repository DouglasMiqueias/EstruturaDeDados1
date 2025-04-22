#include <stdio.h>
#include <stdbool.h>

#define MAX 20

// Estrutura do conjunto
typedef struct {
    int elementos[MAX];
    int tamanho;
} Conjunto;

// a. Criar um conjunto vazio
void criarConjuntoVazio(Conjunto *c) {
    c->tamanho = 0;
}

// b. Ler os dados de um conjunto (sem permitir repetidos)
void lerConjunto(Conjunto *c) {
    int valor;
    printf("Digite o número de elementos (máximo %d): ", MAX);
    scanf("%d", &c->tamanho);

    if (c->tamanho > MAX) {
        printf("Tamanho excede o máximo permitido!\n");
        c->tamanho = MAX;
    }

    for (int i = 0; i < c->tamanho; ) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &valor);

        // Verifica se já existe
        bool repetido = false;
        for (int j = 0; j < i; j++) {
            if (c->elementos[j] == valor) {
                repetido = true;
                break;
            }
        }

        if (!repetido) {
            c->elementos[i] = valor;
            i++;
        } else {
            printf("Elemento repetido! Digite outro valor.\n");
        }
    }
}

// Verifica se um elemento pertence a um conjunto
bool pertence(Conjunto *c, int valor) {
    for (int i = 0; i < c->tamanho; i++) {
        if (c->elementos[i] == valor)
            return true;
    }
    return false;
}

// c. União de dois conjuntos
Conjunto uniao(Conjunto *a, Conjunto *b) {
    Conjunto resultado;
    criarConjuntoVazio(&resultado);

    // Adiciona todos de A
    for (int i = 0; i < a->tamanho; i++) {
        resultado.elementos[resultado.tamanho++] = a->elementos[i];
    }

    // Adiciona os de B que não estão em A
    for (int i = 0; i < b->tamanho; i++) {
        if (!pertence(a, b->elementos[i]) && resultado.tamanho < MAX) {
            resultado.elementos[resultado.tamanho++] = b->elementos[i];
        }
    }

    return resultado;
}

// d. Interseção de dois conjuntos
Conjunto interseccao(Conjunto *a, Conjunto *b) {
    Conjunto resultado;
    criarConjuntoVazio(&resultado);

    for (int i = 0; i < a->tamanho; i++) {
        if (pertence(b, a->elementos[i])) {
            resultado.elementos[resultado.tamanho++] = a->elementos[i];
        }
    }

    return resultado;
}

// e. Imprimir um conjunto
void imprimirConjunto(Conjunto *c) {
    printf("{ ");
    for (int i = 0; i < c->tamanho; i++) {
        printf("%d", c->elementos[i]);
        if (i < c->tamanho - 1)
            printf(", ");
    }
    printf(" }\n");
}

// Função principal para testes
int main() {
    Conjunto A, B, C;

    printf("Lendo conjunto A:\n");
    lerConjunto(&A);
    printf("Lendo conjunto B:\n");
    lerConjunto(&B);

    printf("\nConjunto A: ");
    imprimirConjunto(&A);

    printf("Conjunto B: ");
    imprimirConjunto(&B);

    C = uniao(&A, &B);
    printf("\nUnião: ");
    imprimirConjunto(&C);

    C = interseccao(&A, &B);
    printf("Interseção: ");
    imprimirConjunto(&C);

    return 0;
}
