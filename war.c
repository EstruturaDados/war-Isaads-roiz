#include <stdio.h>
#include <string.h>

// Tamanho máximo do vetor de territórios, conforme requisito
#define MAX_TERRITORIOS 5

/**
 * @brief Definição da estrutura (struct) Territorio.
 */
typedef struct {
    char nome[30];    // Nome do território (máx 29 caracteres + '\0')
    char cor[10];     // Cor do exército que o ocupa (máx 9 caracteres + '\0')
    int tropas;       // Quantidade de tropas no território
} Territorio;

/**
 * @brief Limpa o buffer de entrada (stdin) para remover caracteres residuais,
 * como o '\n' (Enter), que podem atrapalhar leituras subsequentes.
 */
void limpar_buffer() {
    int c;
    // Lê e descarta caracteres do buffer até encontrar um '\n' ou o fim do arquivo (EOF)
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * @brief Função principal do programa.
 */
int main() {
    Territorio territorios[MAX_TERRITORIOS];
    int i; 

    printf("--- Cadastro de Territórios ---\n");
    printf("Por favor, preencha os dados de %d territórios.\n\n", MAX_TERRITORIOS);

    // 2. Entrada dos Dados (Cadastro dos territórios)
    for (i = 0; i < MAX_TERRITORIOS; i++) {
        printf("=== Território %d de %d ===\n", i + 1, MAX_TERRITORIOS);

        // Entrada do Nome do Território
        printf("Digite o NOME do território (max 29): ");
        scanf("%29s", territorios[i].nome);
        // Após ler a string, é bom limpar o buffer caso o nome digitado tenha
        // sido maior que 29 caracteres e tenha deixado dados residuais.
        limpar_buffer();

        // Entrada da Cor do Exército
        printf("Digite a COR do exército (max 9): ");
        scanf("%9s", territorios[i].cor);
        limpar_buffer();

        // Entrada da Quantidade de Tropas
        printf("Digite a QUANTIDADE de tropas: ");
        if (scanf("%d", &territorios[i].tropas) != 1) {
            printf("Aviso: Entrada inválida. Tente novamente.\n");
            // Se a leitura do inteiro falhar, o buffer DEVE ser limpo
            limpar_buffer(); 
            i--; // Decrementa 'i' para repetir a leitura do território atual
            continue; // Pula para a próxima iteração do loop
        }
        
        // **IMPORTANTE**: Limpa o '\n' (Enter) deixado pelo scanf("%d", ...)
        // para que não seja lido na próxima iteração do loop.
        limpar_buffer();
        
        printf("\n"); // Adiciona uma linha em branco para melhor visualização
    }
    
    printf("--- Cadastro concluído! ---\n\n");
    
    // 3. Exibição dos Dados
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