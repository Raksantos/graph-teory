# Algoritmo de Ford-Fulkerson

## Compilando
```
make ford_fulkerson
```

## Entrada

A primeira linha da entrada deve ser composta por dois números inteiros: **n** e **m**. Onde **n** = número de vértices e **m** = número de arestas do grafo.

A segunda linha da entrada deve ser composta por dois inteiros, **s** e **t**. Onde **s** é o vértice de origem e **t** é o vértice de destino.

Em seguida, **m** linhas, que representam as arestas do grafo, cada uma com três inteiros: **v1**, **v2** e **c**. Onde **v1** e **v2** são os vértices conectados pela aresta e **c** é a capacidade da aresta. Note que o grafo é direcionado, logo a aresta tem sentido **v1** -> **v2**.

Note que os vértices são numerados de **0** a **n - 1**, logo, para funcionamento correto do alogritmo, a entrada deve ser feita respeitando esses limites ao identificar os vértices.

Essa entrada pode ser feita interativamente pelo terminal, ou por meio de arquivo de texto.

### Exemplo

Exemplo contido no arquivo `ford_fulkerson.in`, para um grafo de 8 vértices e 13 arestas:

```
6 9
0 3
0 1 7
0 5 4
1 2 5
1 4 3
2 3 8
4 3 5
5 1 3
5 4 2
```

## Executando

```
./ford_fulkerson < ford_fulkerson.in
```

## Saída

A saída será uma string `O fluxo maximo desse grafo eh: F`, onde F é um inteiro que representa o fluxo máximo do grafo de acordo com o algoritmo de Ford-Fulkerson.

### Exemplo

A saída para o algoritmo executado sobre o grafo de entrada apresentado no arquivo `ford_fulkerson.in` seria:

```
O fluxo maximo desse grafo eh: 10
```