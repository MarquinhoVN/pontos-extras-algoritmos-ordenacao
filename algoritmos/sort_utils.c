#include "sort_utils.h"
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

long long comparacoes = 0;

#include <stdio.h>
#include <stdlib.h>

int* ler_arquivo(const char *nome_arquivo, int *tamanho) {
    FILE *fp = fopen(nome_arquivo, "r");
    if (!fp) {
        perror("Erro ao abrir arquivo");
        exit(1);
    }
    int contador = 0;
    int valor;
    while (fscanf(fp, "%d", &valor) == 1) {
        contador++;
    }

    int *vetor = malloc(sizeof(int) * contador);
    if (vetor == NULL) {
        perror("Erro de alocação de memória");
        exit(1);
    }

    rewind(fp);

    int i = 0;
    while (fscanf(fp, "%d", &valor) == 1) {
        vetor[i++] = valor;
    }

    fclose(fp);
    *tamanho = contador; 
    return vetor;
}

void salvar_resultado(const char *algoritmo, const char *arquivo, long long comparacoes, double tempo) {
    FILE *fp = fopen("../resultados/resultados.csv", "a");
    if (!fp) {
        perror("Erro ao salvar resultado");
        exit(1);
    }
    fprintf(fp, "%s,%s,%lld,%.6f\n", algoritmo, arquivo, comparacoes, tempo);
    fclose(fp);
}

void listar_arquivos(const char *pasta, char arquivos[][256], int *total) {
    DIR *dir = opendir(pasta);
    struct dirent *entry;
    *total = 0;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            snprintf(arquivos[*total], 256, "%s/%s", pasta, entry->d_name);
            (*total)++;
        }
    }

    closedir(dir);
}
