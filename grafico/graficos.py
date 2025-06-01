import pandas as pd
import matplotlib.pyplot as plt
import os
import re

df = pd.read_csv("../resultados/resultados.csv", dtype={
    "algoritmo": str,
    "arquivo": str,
    "comparacoes": int,
    "tempo": float
})

def extrair_info(caminho):
    match = re.search(r'entrada_([a-z]+)_(\d+)\.txt', caminho)
    if match:
        return match.group(1), int(match.group(2))
    return None, None

df[["tipo", "tamanho"]] = df["arquivo"].apply(lambda x: pd.Series(extrair_info(x)))

df = df.dropna(subset=["tipo", "tamanho"])

grupos = df.groupby(["tipo", "tamanho"])

os.makedirs("graficos", exist_ok=True)

for (tipo, tamanho), grupo in grupos:
    if grupo.empty:
        continue  

    media = grupo.groupby("algoritmo", as_index=False).agg({
        "tempo": "mean",
        "comparacoes": "mean"
    })

    fig, ax1 = plt.subplots(figsize=(10, 6))

    ax1.bar(media["algoritmo"], media["tempo"], color="steelblue", label="Tempo médio (s)")
    ax1.set_ylabel("Tempo médio (s)", color="steelblue")
    ax1.tick_params(axis='y', labelcolor='steelblue')

    ax2 = ax1.twinx()
    ax2.plot(media["algoritmo"], media["comparacoes"], color="darkorange", marker="o", linewidth=2, label="Comparações médias")
    ax2.set_ylabel("Comparações médias", color="darkorange")
    ax2.tick_params(axis='y', labelcolor='darkorange')

    plt.title(f"Desempenho dos Algoritmos - Tipo: {tipo.capitalize()}, Tamanho: {tamanho}")
    ax1.set_xlabel("Algoritmo")

    h1, l1 = ax1.get_legend_handles_labels()
    h2, l2 = ax2.get_legend_handles_labels()
    ax1.legend(h1 + h2, l1 + l2, loc="upper left")

    nome_arquivo = f"graficos/grafico_{tipo}_{tamanho}.png"
    plt.tight_layout()
    plt.savefig(nome_arquivo)
    plt.close()
    print(f"Gráfico salvo: {nome_arquivo}")
