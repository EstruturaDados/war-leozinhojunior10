#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura que representa um território
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// ---------- Protótipos das funções ----------
void cadastrarTerritorios(Territorio *mapa, int n);
void exibirTerritorios(Territorio *mapa, int n);
void atacar(Territorio *atacante, Territorio *defensor);
void liberarMemoria(Territorio *mapa);
int escolherTerritorio(Territorio *mapa, int n, char tipo[]);

// ---------- Função principal ----------
int main() {
    srand(time(NULL)); // garante aleatoriedade nas rolagens

    int n;
    printf("Quantos territorios deseja cadastrar? ");
    scanf("%d", &n);
    getchar(); // limpa o buffer

    // Alocação dinâmica de memória
    Territorio *mapa = (Territorio *)calloc(n, sizeof(Territorio));
    if (mapa == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    // Cadastro inicial
    cadastrarTerritorios(mapa, n);

    char opcao;
    do {
        printf("\n--- MENU DE ACOES ---\n");
        printf("1 - Exibir territorios\n");
        printf("2 - Realizar ataque\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf(" %c", &opcao);
        getchar();

        switch (opcao) {
            case '1':
                exibirTerritorios(mapa, n);
                break;
            case '2': {
                int idxAtacante = escolherTerritorio(mapa, n, "atacante");
                int idxDefensor = escolherTerritorio(mapa, n, "defensor");

                if (strcmp(mapa[idxAtacante].cor, mapa[idxDefensor].cor) == 0) {
                    printf("\n❌ O atacante e o defensor nao podem ser do mesmo exercito!\n");
                    break;
                }

                atacar(&mapa[idxAtacante], &mapa[idxDefensor]);
                exibirTerritorios(mapa, n);
                break;
            }
            case '0':
                printf("\nEncerrando programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != '0');

    liberarMemoria(mapa);
    return 0;
}

// ---------- Funções auxiliares ----------

// Cadastra todos os territórios
void cadastrarTerritorios(Territorio *mapa, int n) {
    printf("\n--- Cadastro de Territorios ---\n");
    for (int i = 0; i < n; i++) {
        printf("\nTerritorio %d:\n", i + 1);
        printf("Nome: ");
        fgets(mapa[i].nome, 30, stdin);
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0'; // remove \n
        printf("Cor do exercito: ");
        fgets(mapa[i].cor, 10, stdin);
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = '\0';
        printf("Quantidade de tropas: ");
        scanf("%d", &mapa[i].tropas);
        getchar();
    }
}

// Exibe os dados dos territórios
void exibirTerritorios(Territorio *mapa, int n) {
    printf("\n--- Situacao dos Territorios ---\n");
    for (int i = 0; i < n; i++) {
        printf("%d) %-15s | Cor: %-10s | Tropas: %d\n",
               i, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
}

// Simula um ataque entre dois territórios
void atacar(Territorio *atacante, Territorio *defensor) {
    printf("\n=== Ataque: %s (%s) -> %s (%s) ===\n",
           atacante->nome, atacante->cor, defensor->nome, defensor->cor);

    if (atacante->tropas < 2) {
        printf("❌ O atacante precisa ter pelo menos 2 tropas para atacar!\n");
        return;
    }

    int dadoAtacante = (rand() % 6) + 1;
    int dadoDefensor = (rand() % 6) + 1;

    printf("Dado atacante: %d | Dado defensor: %d\n", dadoAtacante, dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        printf("✅ O atacante venceu a batalha!\n");
        strcpy(defensor->cor, atacante->cor); // muda o dono do território
        defensor->tropas = atacante->tropas / 2; // transfere metade das tropas
        atacante->tropas -= defensor->tropas / 2; // atacante perde algumas tropas
    } else {
        printf("❌ O defensor resistiu! O atacante perde 1 tropa.\n");
        atacante->tropas -= 1;
        if (atacante->tropas < 0) atacante->tropas = 0;
    }
}

// Função para o usuário escolher o índice de um território
int escolherTerritorio(Territorio *mapa, int n, char tipo[]) {
    exibirTerritorios(mapa, n);
    int escolha;
    printf("\nEscolha o territorio %s (indice): ", tipo);
    scanf("%d", &escolha);
    getchar();
    if (escolha < 0 || escolha >= n) {
        printf("Indice invalido! Escolhendo o primeiro territorio por padrao.\n");
        return 0;
    }
    return escolha;
}

// Libera memória alocada dinamicamente
void liberarMemoria(Territorio *mapa) {
    free(mapa);
    printf("\nMemoria liberada
