#include <stdio.h>
#include <string.h>

/*
 * Estrutura que representa um território no jogo.
 * Armazena o nome do território, a cor do exército que o controla
 * e a quantidade de tropas disponíveis.
 */
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

int main() {
    // Declaração de um vetor com 5 territórios
    struct Territorio territorios[5];

    printf("=== Cadastro de Territorios ===\n");

    // Loop para cadastro dos 5 territórios
    for (int i = 0; i < 5; i++) {
        printf("\nTerritorio %d:\n", i + 1);

        printf("Nome do territorio: ");
        scanf("%s", territorios[i].nome); // lê o nome (sem espaços)

        printf("Cor do exercito: ");
        scanf("%s", territorios[i].cor); // lê a cor (sem espaços)

        printf("Quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);
    }

    // Exibição dos dados logo após o cadastro
    printf("\n=== Lista de Territorios Cadastrados ===\n");
    for (int i = 0; i < 5; i++) {
        printf("\nTerritorio %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do exercito: %s\n", territorios[i].cor);
        printf("Quantidade de tropas: %d\n", territorios[i].tropas);
    }

    printf("\nCadastro concluido com sucesso!\n");
    return 0;
}
