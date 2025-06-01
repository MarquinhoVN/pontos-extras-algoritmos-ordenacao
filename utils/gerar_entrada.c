#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarOrdenado(const char *nomeArquivo, int tamanho) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (!arquivo) {
        perror("Erro ao abrir arquivo para escrita");
        return;
    }
    for (int i = 1; i <= tamanho; i++) {
        fprintf(arquivo, "%d\n", i);
    }
    fclose(arquivo);
}

void gerarDecrescente(const char *nomeArquivo, int tamanho) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (!arquivo) {
        perror("Erro ao abrir arquivo para escrita");
        return;
    }
    for (int i = tamanho; i >= 1; i--) {
        fprintf(arquivo, "%d\n", i);
    }
    fclose(arquivo);
}

void gerarAleatorio(const char *nomeArquivo, int tamanho) {
    int *array = malloc(tamanho * sizeof(int));
    if (!array) {
        perror("Erro ao alocar memória");
        return;
    }

    for (int i = 0; i < tamanho; i++) {
        array[i] = i + 1;
    }

    for (int i = tamanho - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    FILE *arquivo = fopen(nomeArquivo, "w");
    if (!arquivo) {
        perror("Erro ao abrir arquivo para escrita");
        free(array);
        return;
    }

    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d\n", array[i]);
    }

    fclose(arquivo);
    free(array);
}

int main() {
    srand(time(NULL));

    int tamanhos[] = {1000, 10000, 100000, 500000, 1000000};
    int qtdTamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    for (int i = 0; i < qtdTamanhos; i++) {
        int tam = tamanhos[i];

        char nomeOrdenado[64];
        char nomeDecrescente[64];
        char nomeAleatorio[64];

        sprintf(nomeOrdenado, "entrada_ordenada_%d.txt", tam);
        sprintf(nomeDecrescente, "entrada_decrescente_%d.txt", tam);
        sprintf(nomeAleatorio, "entrada_aleatoria_%d.txt", tam);

        printf("Gerando arquivos para tamanho %d...\n", tam);

        gerarOrdenado(nomeOrdenado, tam);
        gerarDecrescente(nomeDecrescente, tam);
        gerarAleatorio(nomeAleatorio, tam);
    }

    printf("Todos os arquivos foram gerados com sucesso.\n");

    return 0;
}
