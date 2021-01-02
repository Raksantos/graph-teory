#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"

void erro_entrada();

int main() {
    int numero_vertices, grau_maximo, numero_arestas, eh_digrafo;
    scanf("%d %d %d %d", &numero_vertices, &grau_maximo, &numero_arestas, &eh_digrafo);

    // para dijkstra, assumimos que o grafo é ponderado
    Grafo *gr = cria_grafo(numero_vertices, grau_maximo, 1, eh_digrafo);

    int origem, objetivo;
    scanf("%d %d", &origem, &objetivo);

    if(origem < 0 || origem >= numero_vertices || objetivo < 0 || objetivo >= numero_vertices) {
        erro_entrada();
    }

    int i, v1, v2, peso;
    for(i = 0; i < numero_arestas; i++) {
        scanf("%d %d %d", &v1, &v2, &peso);
        if(v1 < 0 || v1 >= numero_vertices || v2 < 0 || v2 >= numero_vertices) {
            erro_entrada();
        }
        insere_aresta(gr, v1, v2, peso);
    }

    int ant[numero_vertices];
    int dist[numero_vertices];
    int caminho[numero_vertices];
    int contador = numero_vertices - 1;

    for(i = 0; i < numero_vertices; i++){
        ant[i] = -1;
    }

    dijkstra(gr, origem, ant, dist);

    int encontrado = encontra_caminho(origem, objetivo, numero_vertices, caminho, ant, contador);
    
    if(encontrado) {
        imprime_caminho(origem, numero_vertices, caminho);
    }

    libera_grafo(gr);

    return 0;
}

void erro_entrada() {
    printf("Erro nos valores de entrada\n");
    printf("Vértice está fora dos limites de 0 a n - 1\n");
    exit(-1);
}