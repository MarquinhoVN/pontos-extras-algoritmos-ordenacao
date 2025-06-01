#ifndef SORT_UTILS_H
#define SORT_UTILS_H

#include <stdio.h>
#include <stdlib.h>

extern long long comparacoes;

int* ler_arquivo(const char *nome_arquivo, int *tamanho);
void salvar_resultado(const char *algoritmo, const char *arquivo, long long comparacoes, double tempo);
void listar_arquivos(const char *pasta, char arquivos[][256], int *total);

#endif
