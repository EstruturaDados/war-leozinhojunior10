#include <stdio.h>
#include <string.h>

// Definição da struct (Documentação/Manutenibilidade)
// A struct Territorio armazena os dados de um único território.
typedef struct {
    char nome[30];  // Nome do território (até 29 caracteres + '\0')
    char cor[10];   // Cor do exército que domina o território
    int tropas;     // Quantidade de tropas presentes no território
} Territorio;

// Constante para o número de territórios a serem cadastrados
#define NUM_TERRITORIOS 5

int main() {
    // Declaração de vetor de structs (Manutenibilidade)
    // Cria um array (vetor) capaz de armazenar 5 estruturas Territorio.
    Territorio listaTerritorios[NUM_TERRITORIOS];
    
    int i; // Variável de controle do laço for

    // -----------------------------------------------------------
    // Etapa 1: Cadastro dos territórios (Usabilidade/Entrada dos dados)
    // -----------------------------------------------------------
    printf("--- Cadastro de %d Territórios ---\n\n", NUM_TERRITORIOS);

    // Laço for para preencher os dados dos 5 territórios
    // (Documentação/Lógica de Entrada)
    for (i = 0; i < NUM_TERRITORIOS; i++) {
        printf("Território #%d:\n", i + 1);

        // Entrada do Nome
        // Usa fgets para ler a linha inteira (incluindo espaços) e evitar buffer
        // (Requisito: Usabilidade)
        printf("  Nome do Território (máx. 29 caracteres): ");
        // Garante que a leitura do nome limpa o '\n' se for digitado
        // O fgets é mais seguro, mas para seguir o requisito de usar scanf para nome/tropas:
        
        // Limpa o buffer de entrada antes de ler a string, se necessário
        // while (getchar() != '\n'); 

        // Lê a string (nome) sem espaços até 29 caracteres
        // Usando %29s para evitar overflow e atendendo ao requisito de usar scanf
        // Se o nome puder ter espaços, seria necessário usar: scanf(" %29[^\n]", listaTerritorios[i].nome);
        scanf("%29s", listaTerritorios[i].nome); 

        // Entrada da Cor
        printf("  Cor do Exército (máx. 9 caracteres): ");
        scanf("%9s", listaTerritorios[i].cor);
        
        // Entrada de Tropas
        // (Requisito: Usabilidade, usa scanf)
        printf("  Quantidade de Tropas: ");
        // O %d do scanf lê o inteiro e deixa o \n no buffer, o que não afeta a próxima leitura de string/int.
        scanf("%d", &listaTerritorios[i].tropas);
        
        printf("\n"); // Espaçamento para o próximo cadastro
    }

    // -----------------------------------------------------------
    // Etapa 2: Exibição dos dados (Desempenho/Exibição)
    // -----------------------------------------------------------
    printf("===================================\n");
    printf("=== Dados dos Territórios Cadastrados ===\n");
    printf("===================================\n\n");

    // Laço for para exibir os dados dos 5 territórios
    // (Documentação/Lógica de Saída)
    for (i = 0; i < NUM_TERRITORIOS; i++) {
        printf("--- Território #%d ---\n", i + 1);
        printf("Nome:  **%s**\n", listaTerritorios[i].nome);
        printf("Cor:   %s\n", listaTerritorios[i].cor);
        printf("Tropas: %d\n", listaTerritorios[i].tropas);
        printf("----------------------\n\n");
    }

    return 0;
}
