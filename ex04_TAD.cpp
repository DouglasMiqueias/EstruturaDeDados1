#include <stdio.h>
#include <string.h>

#define MAX_LIVROS 10

typedef struct {
    char titulo[100];
    char autor[100];
    int paginas;
} Livro;

// Fun��o para ler um livro
Livro lerLivro() {
    Livro l;

    printf("T�tulo: ");
    fgets(l.titulo, sizeof(l.titulo), stdin);
    l.titulo[strcspn(l.titulo, "\n")] = '\0';  // Remove o \n

    printf("Autor: ");
    fgets(l.autor, sizeof(l.autor), stdin);
    l.autor[strcspn(l.autor, "\n")] = '\0';  // Remove o \n

    printf("N�mero de p�ginas: ");
    scanf("%d", &l.paginas);
    getchar(); // Limpa o buffer do enter

    return l;
}

// Fun��o para imprimir um livro
void imprimirLivro(Livro l) {
    printf("T�tulo: %s\n", l.titulo);
    printf("Autor: %s\n", l.autor);
    printf("P�ginas: %d\n", l.paginas);
}

typedef struct {
    Livro livros[MAX_LIVROS];
    int quantidade;
} Biblioteca;

// Adicionar um novo livro � biblioteca
void adicionarLivro(Biblioteca *b) {
    if (b->quantidade >= MAX_LIVROS) {
        printf("A biblioteca est� cheia! N�o � poss�vel adicionar mais livros.\n");
        return;
    }

    printf("\n=== Cadastro de novo livro ===\n");
    b->livros[b->quantidade] = lerLivro();
    b->quantidade++;

    printf("Livro adicionado com sucesso!\n");
}

// Imprimir todos os livros da biblioteca
void imprimirTodosLivros(Biblioteca b) {
    if (b.quantidade == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    printf("\n=== Lista de Livros ===\n");
    for (int i = 0; i < b.quantidade; i++) {
        printf("\nLivro %d:\n", i + 1);
        imprimirLivro(b.livros[i]);
    }
}

// Imprimir o livro com mais p�ginas
void imprimirLivroMaisPaginas(Biblioteca b) {
    if (b.quantidade == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    int indiceMaior = 0;
    for (int i = 1; i < b.quantidade; i++) {
        if (b.livros[i].paginas > b.livros[indiceMaior].paginas) {
            indiceMaior = i;
        }
    }

    printf("\n=== Livro com maior n�mero de p�ginas ===\n");
    imprimirLivro(b.livros[indiceMaior]);
}

int main() {
    Biblioteca biblioteca;
    biblioteca.quantidade = 0;

    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Adicionar novo livro\n");
        printf("2. Imprimir todos os livros\n");
        printf("3. Livro com mais p�ginas\n");
        printf("0. Sair\n");
        printf("Escolha uma op��o: \n");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer

        switch (opcao) {
            case 1:
                adicionarLivro(&biblioteca);
                break;
            case 2:
                imprimirTodosLivros(biblioteca);
                break;
            case 3:
                imprimirLivroMaisPaginas(biblioteca);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Op��o inv�lida!\n");
        }

    } while (opcao != 0);

    return 0;
}
