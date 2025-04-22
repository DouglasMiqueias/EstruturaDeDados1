#include <stdio.h>
#include <string.h>

#define MAX_FUNCIONARIOS 10

// Estrutura para funcion�rio
typedef struct {
    char nome[50];
    char cargo[50];
    float salarioBase;
    float beneficios;
    float descontos;
} Funcionario;

// Fun��o para calcular sal�rio l�quido
float calcularSalarioLiquido(Funcionario f) {
    return f.salarioBase + f.beneficios - f.descontos;
}

// Fun��o para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Fun��o para cadastrar os funcion�rios
void cadastrarFuncionarios(Funcionario funcionarios[], int *quantidade) {
    printf("Digite o n�mero de funcion�rios (m�ximo %d): ", MAX_FUNCIONARIOS);
    scanf("%d", quantidade);
    limparBuffer();

    if (*quantidade > MAX_FUNCIONARIOS) {
        printf("Limite excedido! Ser�o cadastrados apenas os %d primeiros.\n", MAX_FUNCIONARIOS);
        *quantidade = MAX_FUNCIONARIOS;
    }

    for (int i = 0; i < *quantidade; i++) {
        printf("\n--- Funcion�rio %d ---\n", i + 1);

        printf("Nome: ");
        fgets(funcionarios[i].nome, sizeof(funcionarios[i].nome), stdin);
        funcionarios[i].nome[strcspn(funcionarios[i].nome, "\n")] = '\0';

        printf("Cargo: ");
        fgets(funcionarios[i].cargo, sizeof(funcionarios[i].cargo), stdin);
        funcionarios[i].cargo[strcspn(funcionarios[i].cargo, "\n")] = '\0';

        printf("Sal�rio base: R$ ");
        scanf("%f", &funcionarios[i].salarioBase);
        limparBuffer();

        printf("Benef�cios: R$ ");
        scanf("%f", &funcionarios[i].beneficios);
        limparBuffer();

        printf("Descontos: R$ ");
        scanf("%f", &funcionarios[i].descontos);
        limparBuffer();
    }
}

// Fun��o para exibir dados dos funcion�rios e calcular m�dia
void exibirFuncionarios(Funcionario funcionarios[], int quantidade) {
    float somaSalarios = 0;
    float maiorSalario = calcularSalarioLiquido(funcionarios[0]);
    int indiceMaior = 0;

    printf("\n=== FOLHA DE PAGAMENTO ===\n");

    for (int i = 0; i < quantidade; i++) {
        float salarioLiquido = calcularSalarioLiquido(funcionarios[i]);
        printf("\nFuncion�rio %d:\n", i + 1);
        printf("Nome: %s\n", funcionarios[i].nome);
        printf("Cargo: %s\n", funcionarios[i].cargo);
        printf("Sal�rio l�quido: R$ %.2f\n", salarioLiquido);

        somaSalarios += salarioLiquido;

        if (salarioLiquido > maiorSalario) {
            maiorSalario = salarioLiquido;
            indiceMaior = i;
        }
    }

    float media = somaSalarios / quantidade;
    printf("\nM�dia salarial da loja: R$ %.2f\n", media);

    printf("\nFuncion�rio com maior sal�rio:\n");
    printf("Nome: %s\n", funcionarios[indiceMaior].nome);
    printf("Cargo: %s\n", funcionarios[indiceMaior].cargo);
    printf("Sal�rio l�quido: R$ %.2f\n", maiorSalario);
}

// Fun��o principal
int main() {
    Funcionario funcionarios[MAX_FUNCIONARIOS];
    int quantidade = 0;

    cadastrarFuncionarios(funcionarios, &quantidade);
    exibirFuncionarios(funcionarios, quantidade);

    return 0;
}
