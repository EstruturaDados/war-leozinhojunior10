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


int ler_string(char *buffer, int tamanho, const char *prompt) {
    printf("  %s: ", prompt);
   
    if (fgets(buffer, tamanho, stdin) == NULL) {
        printf("Erro na leitura.\n");
        return 0; 
    }
    limpar_quebra_linha(buffer);
    return 1; 
}


void limpar_buffer_scanf() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Territorio listaTerritorios[NUM_TERRITORIOS];
    int i;
    
    printf("--- Cadastro de %d Territórios (Processamento Aprimorado) ---\n\n", NUM_TERRITORIOS);
    
    for (i = 0; i < NUM_TERRITORIOS; i++) {
        printf("Território #%d:\n", i + 1);

       
        if (!ler_string(listaTerritorios[i].nome, sizeof(listaTerritorios[i].nome), "Nome do Território")) {
            return 1;
        }

        
        if (!ler_string(listaTerritorios[i].cor, sizeof(listaTerritorios[i].cor), "Cor do Exército")) {
            return 1;
        }
        
     
        printf("  Quantidade de Tropas: ");
        if (scanf("%d", &listaTerritorios[i].tropas) != 1) {
            printf("Entrada de tropas inválida.\n");
            return 1;
        }
        
   
        limpar_buffer_scanf();
        
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
