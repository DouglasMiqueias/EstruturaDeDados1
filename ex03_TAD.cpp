#include <stdio.h>
#include <string.h>

#define MAX_FUNCIONARIOS 10

// Estrutura para funcionário
typedef struct {
    char nome[50];
    char cargo[50];
    float salarioBase;
    float beneficios;
    float descontos;
} Funcionario;

// Função para calcular salário líquido
float calcularSalarioLiquido(Funcionario f) {
    return f.salarioBase + f.beneficios - f.descontos;
}

// Função para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para cadastrar os funcionários
void cadastrarFuncionarios(Funcionario funcionarios[], int *quantidade) {
    printf("Digite o número de funcionários (máximo %d): ", MAX_FUNCIONARIOS);
    scanf("%d", quantidade);
    limparBuffer();

    if (*quantidade > MAX_FUNCIONARIOS) {
        printf("Limite excedido! Serão cadastrados apenas os %d primeiros.\n", MAX_FUNCIONARIOS);
        *quantidade = MAX_FUNCIONARIOS;
    }

    for (int i = 0; i < *quantidade; i++) {
        printf("\n--- Funcionário %d ---\n", i + 1);

        printf("Nome: ");
        fgets(funcionarios[i].nome, sizeof(funcionarios[i].nome), stdin);
        funcionarios[i].nome[strcspn(funcionarios[i].nome, "\n")] = '\0';

        printf("Cargo: ");
        fgets(funcionarios[i].cargo, sizeof(funcionarios[i].cargo), stdin);
        funcionarios[i].cargo[strcspn(funcionarios[i].cargo, "\n")] = '\0';

        printf("Salário base: R$ ");
        scanf("%f", &funcionarios[i].salarioBase);
        limparBuffer();

        printf("Benefícios: R$ ");
        scanf("%f", &funcionarios[i].beneficios);
        limparBuffer();

        printf("Descontos: R$ ");
        scanf("%f", &funcionarios[i].descontos);
        limparBuffer();
    }
}

// Função para exibir dados dos funcionários e calcular média
void exibirFuncionarios(Funcionario funcionarios[], int quantidade) {
    float somaSalarios = 0;
    float maiorSalario = calcularSalarioLiquido(funcionarios[0]);
    int indiceMaior = 0;

    printf("\n=== FOLHA DE PAGAMENTO ===\n");

    for (int i = 0; i < quantidade; i++) {
        float salarioLiquido = calcularSalarioLiquido(funcionarios[i]);
        printf("\nFuncionário %d:\n", i + 1);
        printf("Nome: %s\n", funcionarios[i].nome);
        printf("Cargo: %s\n", funcionarios[i].cargo);
        printf("Salário líquido: R$ %.2f\n", salarioLiquido);

        somaSalarios += salarioLiquido;

        if (salarioLiquido > maiorSalario) {
            maiorSalario = salarioLiquido;
            indiceMaior = i;
        }
    }

    float media = somaSalarios / quantidade;
    printf("\nMédia salarial da loja: R$ %.2f\n", media);

    printf("\nFuncionário com maior salário:\n");
    printf("Nome: %s\n", funcionarios[indiceMaior].nome);
    printf("Cargo: %s\n", funcionarios[indiceMaior].cargo);
    printf("Salário líquido: R$ %.2f\n", maiorSalario);
}

// Função principal
int main() {
    Funcionario funcionarios[MAX_FUNCIONARIOS];
    int quantidade = 0;

    cadastrarFuncionarios(funcionarios, &quantidade);
    exibirFuncionarios(funcionarios, quantidade);

    return 0;
}
