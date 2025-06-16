# Análise de Algoritmos - UFRR

**Disciplina:** Análise de Algoritmos  
**Instituição:** Universidade Federal de Roraima (UFRR)  
**Aluno:** Marcos Vinícius Tenacol Coêlho

## Descrição do Projeto

Este projeto tem como objetivo analisar o desempenho de quatro algoritmos de ordenação clássicos: **Merge Sort**, **Insertion Sort**, **Quick Sort** e **Bubble Sort**. A análise é feita com base no tempo de execução de cada algoritmo em diferentes tamanhos de entrada, permitindo observar o comportamento assintótico de cada um.

## Estrutura do Projeto

├── resultados/     # Pasta contendo os resultados gerados
├── grafico/        # Pasta contendo os algoritmos
| ├── graficos/     # pasta contendo os gráficos gerados
│ └── graficos.py   # Algoritmo em python para gerar os gráficos
├── entradas/       # Pasta contendo as entradas geradas
├── algoritmos/     # Pasta contendo os algoritmos
│ ├── bubble_sort.c
│ ├── insertion_sort.c
│ ├── main.c
│ ├── merge_sort.c
│ ├── quick_sort.c
│ ├── sort_utils.c
│ └── sort_utils.h
├── utils/     
│ └── sort_utils.h # Algoritmo para gerar as entradas


## Algoritmos Implementados

### 1. Bubble Sort
Algoritmo de ordenação simples com complexidade quadrática. Não é recomendado para grandes volumes de dados.

### 2. Insertion Sort
Algoritmo eficiente para pequenas entradas. Possui desempenho similar ao Bubble Sort no pior caso.

### 3. Merge Sort
Algoritmo de ordenação por divisão e conquista. Apresenta complexidade estável e desempenho consistente.

### 4. Quick Sort
Algoritmo de ordenação muito eficiente na prática. Também usa divisão e conquista.

## Experimentos Realizados

### Tamanhos de Entrada Testados
- N = 1.000
- N = 10.000
- N = 100.000
- N = 500.000
- N = 1.000.000

### Metodologia
1. **Execuções múltiplas:** Cada algoritmo foi executado 13 vezes por tamanho de entrada.
2. **Medição de tempo:** Uso da função `clock()` da biblioteca `<time.h>` em C.
3. **Análise gráfica:** Geração de gráficos com Python e matplotlib para visualização das tendências.

## Como Executar
### Compilação e Execução
```bash
gcc -o sort_exec main.c sort_utils.c bubble_sort.c insertion_sort.c merge_sort.c quick_sort.c
./main
```
```bash
python grafico/graficos.py
```
# Conclusões
Bubble e Insertion Sort são algoritmos ineficientes para grandes entradas.

Merge Sort é consistente e rápido, mesmo em grandes volumes de dados.

Quick Sort é o mais rápido na média, mas pode ter desempenho ruim em entradas específicas.


