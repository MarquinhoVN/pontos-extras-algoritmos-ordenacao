#include "sort_utils.h"
#include <string.h>
#include <time.h>

#define REPETICOES 13

void bubble_sort(int *arr, int n);
void insertion_sort(int *arr, int n);
void merge_sort(int *arr, int l, int r);
void quick_sort(int *arr, int low, int high);

void executar(const char *algoritmo, void (*sort_fn)(int*, int), char arquivos[][256], int total) {
    for (int i = 0; i < total; i++) {
        for (int j = 0; j < REPETICOES; j++) {
            int n;
            int *dados = ler_arquivo(arquivos[i], &n);
            comparacoes = 0;
            clock_t inicio = clock();

            if (strcmp(algoritmo, "merge") == 0)
                merge_sort(dados, 0, n - 1);
            else if (strcmp(algoritmo, "quick") == 0)
                quick_sort(dados, 0, n - 1);
            else
                sort_fn(dados, n);

            clock_t fim = clock();
            double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
            salvar_resultado(algoritmo, arquivos[i], comparacoes, tempo);
            free(dados);
        }
    }
}

int main() {
    FILE *fp = fopen("../resultados/resultados2.csv", "w");
    if (fp) {
        fprintf(fp, "algoritmo,arquivo,comparacoes,tempo\n");
        fclose(fp);
    }

    char arquivos[15][256];
    int total;
    listar_arquivos("../entradas", arquivos, &total);

    executar("bubble", bubble_sort, arquivos, total);
    executar("insertion", insertion_sort, arquivos, total);
    executar("merge", NULL, arquivos, total);
    executar("quick", NULL, arquivos, total);

    printf("Processamento finalizado! Resultados salvos em resultados/resultados.csv\n");
    return 0;
}
