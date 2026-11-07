#include <stdio.h>
#include <string.h>

// 1 - CADASTRAR
void cadastrar(int codigo[], char nome[][15], int *total) {

    // Verificar se a memoria esta cheia
    if (*total == 5) {
        printf("\nMemoria cheia!\n");
        return;
    }

    // Ler o codigo
    printf("\nDigite o codigo: ");
    scanf("%d", &codigo[*total]);
    getchar();

    // Ler o nome
    printf("Digite o nome: ");
    fgets(nome[*total], 15, stdin);

    // Retirar o \n que pode ser armazenado pelo fgets
    nome[*total][strcspn(nome[*total], "\n")] = '\0';

    // Atualizar a quantidade de registros
    (*total)++;

    printf("\nCadastro realizado com sucesso!\n");
}

// 2 - CONSULTAR
void consultar(int codigo[], char nome[][15], int total) {

    int busca;
    int encontrado = 0;

    printf("\nDigite o codigo para consultar: ");
    scanf("%d", &busca);

    // Percorrer os registros procurando o codigo
    for (int i = 0; i < total; i++) {
        if (codigo[i] == busca) {
            printf("\nCodigo: %d\n", codigo[i]);
            printf("Nome: %s\n", nome[i]);
            encontrado = 1;
            break;
        }
    }

    // Informar se o codigo nao foi encontrado
    if (encontrado == 0) {
        printf("\nRegistro nao encontrado!\n");
    }
}

// 3 - LISTAR
void listar(int codigo[], char nome[][15], int total) {

    if (total == 0) {
        printf("\nNenhum registro cadastrado!\n");
        return;
    }

    printf("\n===== REGISTROS CADASTRADOS =====\n");

    // Percorrer e mostrar todos os registros cadastrados
    for (int i = 0; i < total; i++) {
        printf("Codigo: %d - Nome: %s\n", codigo[i], nome[i]);
    }
}

// 4 - ALTERAR
void alterar(int codigo[], char nome[][15], int total) {

    int busca;
    int encontrado = 0;

    printf("\nDigite o codigo que sera alterado: ");
    scanf("%d", &busca);

    // Procurar o codigo no vetor
    for (int i = 0; i < total; i++) {
        if (codigo[i] == busca) {

            // Ler o novo codigo
            printf("Digite o novo codigo: ");
            scanf("%d", &codigo[i]);
            getchar();

            // Ler o novo nome
            printf("Digite o novo nome: ");
            fgets(nome[i], 15, stdin);
            nome[i][strcspn(nome[i], "\n")] = '\0';

            printf("\nRegistro alterado com sucesso!\n");
            encontrado = 1;
            break;
        }
    }

    // Informar se o codigo nao foi encontrado
    if (encontrado == 0) {
        printf("\nRegistro nao encontrado!\n");
    }
}

// 5 - EXCLUIR
void excluir(int codigo[], char nome[][15], int *total) {

    int busca;
    int encontrado = 0;

    printf("\nDigite o codigo que sera excluido: ");
    scanf("%d", &busca);

    // Procurar o registro no vetor
    for (int i = 0; i < *total; i++) {
        if (codigo[i] == busca) {

            // Deslocar os registros seguintes uma posicao para a esquerda
            for (int j = i; j < *total - 1; j++) {
                codigo[j] = codigo[j + 1];
                strcpy(nome[j], nome[j + 1]);
            }

            // Diminuir a quantidade de registros
            (*total)--;

            printf("\nRegistro excluido com sucesso!\n");
            encontrado = 1;
            break;
        }
    }

    // Informar se o codigo nao foi encontrado
    if (encontrado == 0) {
        printf("\nRegistro nao encontrado!\n");
    }
}

// PROGRAMA PRINCIPAL
int main(void) {

    int codigo[5];
    char nome[5][15];

    int total = 0;
    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Cadastrar\n");
        printf("2 - Consultar\n");
        printf("3 - Listar\n");
        printf("4 - Alterar\n");
        printf("5 - Excluir\n");
        printf("0 - Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar(codigo, nome, &total);
                break;

            case 2:
                consultar(codigo, nome, total);
                break;

            case 3:
                listar(codigo, nome, total);
                break;

            case 4:
                alterar(codigo, nome, total);
                break;

            case 5:
                excluir(codigo, nome, &total);
                break;

            case 0:
                printf("\nEncerrando...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
