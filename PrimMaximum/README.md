# Algoritmo de Prim (Árvore Geradora Máxima)

## Compilando
```
make prim
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

## Saída

A saída será composta de **n** linhas, cada uma no formato `v pai: u` indicando, para cada vértice `v` do grafo, qual seria seu vértice pai (`u`) na árvore geradora máxima. Note que o vértice inicial não possui pai (`-1`), pois a árvore é enraízada nele.

### Exemplo

A saída para o algoritmo executado sobre o grafo de entrada apresentado no arquivo `prim.in` seria:

```
0 pai: -1
1 pai: 0
2 pai: 0
3 pai: 1
4 pai: 1
5 pai: 4
```