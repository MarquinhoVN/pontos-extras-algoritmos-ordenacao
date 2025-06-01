#include "sort_utils.h"

void insertion_sort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int chave = arr[i];
        int j = i - 1;
        while (j >= 0 && (++comparacoes && arr[j] > chave)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = chave;
    }
}
