# Algoritmo de Prim (Árvore Geradora Máxima)

## Compilando
```
gcc operators.cpp heap.cpp prim.cpp main.cpp -o prim -lstdc++
```

## Entrada

A primeira linha da entrada deve ser composta por três números inteiros: **n**, **m**, **v0**. Onde **n** = número de vértices, **m** = número de arestas e **v0** = vértice inicial (0 <= **v0** < **n**).

Em seguida, **m** linhas, que representam as arestas do grafo, cada uma com três inteiros: **v1**, **v2** e **w**. Onde **v1** e **v2** são os vértices conectados pela aresta e **w** é o peso da aresta.

Note que os vértices são numerados de **0** a **n - 1**, logo, para funcionamento correto do algoritmo, a entrada deve ser feita respeitando esses limites ao identificar os vértices.

Essa entrada pode ser feita interativamente pelo terminal, ou por meio de arquivo de texto.

### Exemplo

Exemplo contido no arquivo `prim.in`, para um grafo de 6 vértices e 7 arestas com vértice inicial no 0:

```
6 7 0
0 1 5
0 2 10
1 2 4
1 3 5
1 4 6
1 5 3
4 5 6
```

## Executando

```
./prim < prim.in
```