#include <stdio.h>
#include <string.h>

#define MAX_TERRITORIOS 5

typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Territorio territorios[MAX_TERRITORIOS];
    int i; 

    printf("--- Cadastro de Territórios ---\n");
    printf("Preencha os dados de %d territórios.\n\n", MAX_TERRITORIOS);

    for (i = 0; i < MAX_TERRITORIOS; i++) {
        printf("=== Território %d de %d ===\n", i + 1, MAX_TERRITORIOS);

        printf("Digite o NOME do território (max 29): ");
        scanf("%29s", territorios[i].nome);
        limpar_buffer();

        printf("Digite a COR do exército (max 9): ");
        scanf("%9s", territorios[i].cor);
        limpar_buffer();

        printf("Digite a QUANTIDADE de tropas: ");
        if (scanf("%d", &territorios[i].tropas) != 1) {
            printf("Aviso: Entrada inválida. Tente novamente.\n");
            limpar_buffer(); 
            i--; 
            continue; 
        }
        
        limpar_buffer();
        
        printf("\n");
    }
    
    printf("--- Cadastro concluído! ---\n\n");
    
    printf("--- Dados dos Territórios Cadastrados ---\n");
    printf("==========================================\n");
    
    for (i = 0; i < MAX_TERRITORIOS; i++) {
        printf("Território %d:\n", i + 1);
        printf("  Nome: %s\n", territorios[i].nome);
        printf("  Cor do Exército: %s\n", territorios[i].cor);
        printf("  Tropas: %d\n", territorios[i].tropas);
        printf("------------------------------------------\n");
    }

    return 0;
}