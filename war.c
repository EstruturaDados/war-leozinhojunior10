#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[30];  
    char cor[10];   
    int tropas;   
} Territorio;


#define NUM_TERRITORIOS 5

int main() {
  
   
    Territorio listaTerritorios[NUM_TERRITORIOS];
    
    int i; 

 
    printf("--- Cadastro de %d Territórios ---\n\n", NUM_TERRITORIOS);

 
    for (i = 0; i < NUM_TERRITORIOS; i++) {
        printf("Território #%d:\n", i + 1);

      
        printf("  Nome do Território (máx. 29 caracteres): ");
        
        scanf("%29s", listaTerritorios[i].nome); 

      
        printf("  Cor do Exército (máx. 9 caracteres): ");
        scanf("%9s", listaTerritorios[i].cor);
        
       
        printf("  Quantidade de Tropas: ");
      
        scanf("%d", &listaTerritorios[i].tropas);
        
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
