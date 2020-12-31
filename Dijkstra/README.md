# Algoritmo de Dijkstra

## Compilando
```
gcc graph.c dijkstra.c main.c -o dijkstra
```

## Entrada

A primeira linha da entrada deve ser composta por quatro números inteiros: **n**, **Δ**, **m**, **d**. Onde **n** = número de vértices, **Δ** = grau máximo, **m** = número de arestas e **d** = grafo direcionado (0 ou 1).

A segunda linha da entrada deve ser composta por dois inteiros, **s** e **t**. Onde **s** é o vértice de origem e **t** é o vértice de destino

Em seguida, **m** linhas, que representam as arestas do grafo, cada uma com três inteiros: **v1**, **v2** e **w**. Onde **v1** e **v2** são os vértices conectados pela aresta e **w** é o peso da aresta.

Note que os vértices são numerados de **0** a **n - 1**, logo, para funcionamento correto do alogritmo, a entrada deve ser feita respeitando esses limites ao identificar os vértices.

Essa entrada pode ser feita interativamente pelo terminal, ou por meio de arquivo de texto.

### Exemplo

Exemplo contido no arquivo <span>dijkstra.in</span>, para um grafo de 6 vértices, com grau máximo 4, com 9 arestas e que não é direcionado/digrafo, partindo do vértice 2 e como destino o vértice 4.

```
6 4 9 0
2 4
0 1 1
0 2 9
0 5 14
1 2 10
1 3 15
3 2 11
3 4 6
4 5 9
2 5 2
```

## Executando

```
./dijkstra < dijkstra.in
```