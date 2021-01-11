# Algoritmo de Kruskal

## Compilando
```
make kruskal
```

## Entrada

A primeira linha da entrada deve ser composta por dois números inteiros: **n** e **m**. Onde **n** = número de vértices e **m** = número de arestas do grafo.

Em seguida, **m** linhas, que representam as arestas do grafo, cada uma com três inteiros: **v1**, **v2** e **w**. Onde **v1** e **v2** são os vértices conectados pela aresta e **w** é o peso da aresta.

Note que os vértices são numerados de **0** a **n - 1**, logo, para funcionamento correto do alogritmo, a entrada deve ser feita respeitando esses limites ao identificar os vértices.

Essa entrada pode ser feita interativamente pelo terminal, ou por meio de arquivo de texto.

### Exemplo

Exemplo contido no arquivo `kruskal.in`, para um grafo de 8 vértices e 13 arestas:

```
8 13
0 1 5
1 2 3
1 7 8
1 6 2
2 3 4
2 4 6
2 5 1
2 6 7
3 4 2
4 5 6
5 6 5
6 7 10
7 0 6
```

## Executando

```
./kruskal < kruskal.in
```

## Saída

A saída será composta de **n** - 1 linhas, cada uma no formato `(v1, v2)` indicando as arestas da árvore geradora mínima do grafo de entrada.

### Exemplo

A saída para o algoritmo executado sobre o grafo de entrada apresentado no arquivo `kruskal.in` seria:

```
(2,5)
(1,6)
(3,4)
(1,2)
(2,3)
(0,1)
(7,0)
```