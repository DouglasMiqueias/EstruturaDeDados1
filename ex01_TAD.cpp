#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <string.h> // Para usar strcspn

#define MAX_CLIENTES 50

typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    char nome[50];
    char sexo;
    Data nascimento;
    int idade;
} Cliente;

// Função para calcular idade
int calcularIdade(Data nascimento, Data hoje)
{
    int idade = hoje.ano - nascimento.ano;
    if (hoje.mes < nascimento.mes || (hoje.mes == nascimento.mes && hoje.dia < nascimento.dia))
        idade--;
    return idade;
}

// Função para cadastrar cliente
void cadastrarCliente(Cliente clientes[], int *total, Data dataAtual)
{
    if (*total >= MAX_CLIENTES)
    {
        printf("Limite de clientes atingido!\n");
        return;
    }

    Cliente novo;
    getchar(); // limpar buffer do scanf anterior

    printf("Nome: ");
    fgets(novo.nome, sizeof(novo.nome), stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0'; // remove o \n do final

    printf("Sexo (M/F): ");
    scanf(" %c", &novo.sexo); // espaço antes para ignorar \n pendente

    printf("Data de nascimento (DD MM AAAA): ");
    scanf("%d %d %d", &novo.nascimento.dia, &novo.nascimento.mes, &novo.nascimento.ano);

    novo.idade = calcularIdade(novo.nascimento, dataAtual);

    clientes[*total] = novo;
    (*total)++;

    printf("Cliente cadastrado com sucesso!\n");
}

// Função para listar clientes
void listarClientes(Cliente clientes[], int total)
{
    if (total == 0)
    {
        printf("Nenhum cliente cadastrado ainda.\n");
        return;
    }

    printf("\n--- Lista de Clientes ---\n");
    for (int i = 0; i < total; i++)
    {
        printf("Cliente %d:\n", i + 1);
        printf("Nome: %s\n", clientes[i].nome);
        printf("Sexo: %c\n", clientes[i].sexo);
        printf("Data de nascimento: %02d/%02d/%04d\n",
               clientes[i].nascimento.dia,
               clientes[i].nascimento.mes,
               clientes[i].nascimento.ano);
        printf("Idade: %d anos\n\n", clientes[i].idade);
    }
}

// Função principal
int main()
{
    setlocale(LC_ALL, "Portuguese");

    Cliente clientes[MAX_CLIENTES];
    int totalClientes = 0;

    Data hoje;

    // Pega data atual do sistema
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    hoje.dia = tm.tm_mday;
    hoje.mes = tm.tm_mon + 1;
    hoje.ano = tm.tm_year + 1900;

    int opcao;

    do
    {
        printf("\n===== MENU =====\n");
        printf("1. Cadastrar cliente\n");
        printf("2. Listar clientes\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrarCliente(clientes, &totalClientes, hoje);
            break;
        case 2:
            listarClientes(clientes, totalClientes);
            break;
        case 0:
            printf("Encerrando o programa...\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
