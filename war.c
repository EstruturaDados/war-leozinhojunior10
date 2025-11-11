#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

#define NUM_TERRITORIOS 5

void limpar_quebra_linha(char *string) {
    size_t len = strlen(string);
    if (len > 0 && string[len - 1] == '\n') {
        string[len - 1] = '\0';
    }
}

int main() {
    Territorio listaTerritorios[NUM_TERRITORIOS];
    int i;
    
    printf("--- Cadastro de %d Territórios ---\n\n", NUM_TERRITORIOS);
    
    for (i = 0; i < NUM_TERRITORIOS; i++) {
        printf("Território #%d:\n", i + 1);

        printf("  Nome do Território (máx. 29 caracteres): ");
        if (fgets(listaTerritorios[i].nome, sizeof(listaTerritorios[i].nome), stdin) == NULL) {
            return 1;
        }
        limpar_quebra_linha(listaTerritorios[i].nome);

        printf("  Cor do Exército (máx. 9 caracteres): ");
        if (fgets(listaTerritorios[i].cor, sizeof(listaTerritorios[i].cor), stdin) == NULL) {
            return 1;
        }
        limpar_quebra_linha(listaTerritorios[i].cor);
        
        printf("  Quantidade de Tropas: ");
        if (scanf("%d", &listaTerritorios[i].tropas) != 1) {
            printf("Entrada inválida.\n");
            return 1;
        }
        
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        
        printf("\n");
    }

    printf("===================================\n");
    printf("=== Dados dos Territórios Cadastrados ===\n");
    printf("===================================\n\n");

    for (i = 0; i < NUM_TERRITORIOS; i++) {
        printf("--- Território #%d ---\n", i + 1);
        printf("Nome:  **%s**\n", listaTerritorios[i].nome);
        printf("Cor:   %s\n", listaTerritorios[i].cor);
        printf("Tropas: %d\n", listaTerritorios[i].tropas);
        printf("----------------------\n\n");
    }

    return 0;
}
