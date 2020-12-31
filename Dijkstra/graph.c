#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Grafo *cria_grafo(int nro_vertices, int grau_max, int eh_ponderado, int eh_digrafo){
    Grafo *gr = (Grafo*) malloc(sizeof(struct grafo));

    if(gr != NULL){
        int i, j;
        gr->nro_vertices = nro_vertices;
        gr->grau_max = grau_max;
        gr->eh_ponderado = eh_ponderado;
        gr->eh_digrafo = eh_digrafo;

        gr->grau = (int*) calloc(nro_vertices, sizeof(int));

        gr->arestas = (int**)malloc(nro_vertices*sizeof(int*));

        for(i = 0; i < nro_vertices; i++){
            gr->arestas[i] = (int*)malloc(grau_max*sizeof(int));

            if(gr->eh_ponderado){
                gr->pesos = (int**) malloc(nro_vertices*sizeof(int*));

                for(j = 0; j < nro_vertices; j++){
                    gr->pesos[j] = (int*)malloc(grau_max*sizeof(int));
                }
            }
        }
    }

    return gr;
}

int insere_aresta(Grafo* gr, int origem, int destino, int peso){
    if(gr == NULL) return 0;

    if(origem < 0 || origem >= gr->nro_vertices) return 0;

    if(destino < 0 || destino >= gr->nro_vertices) return 0;

    gr->arestas[origem][gr->grau[origem]] = destino;

    if(gr->eh_ponderado){
        gr->pesos[origem][gr->grau[origem]] = peso;
    }

    gr->grau[origem]++;

    if(gr->eh_digrafo == 0) {
        gr->arestas[destino][gr->grau[destino]] = origem;
        if(gr->eh_ponderado){
            gr->pesos[destino][gr->grau[destino]] = peso;
        }
        gr->grau[destino]++;
    }

    return 1;
}

void libera_grafo(Grafo *gr){
    if(gr != NULL){
        int i;
        for(i = 0; i < gr->nro_vertices; i++){
            free(gr->arestas[i]);
        }
        free(gr->arestas);

        if(gr->eh_ponderado){
            for(i = 0; i < gr->nro_vertices; i++){
                free(gr->pesos[i]);
            }
            free(gr->pesos);
        }
        free(gr->grau);
        free(gr);
    }
}

void printa_grafo(Grafo *gr, int nro_vertices){
    int i, j;

    if(gr == NULL) return;

    for(i = 0; i < gr->nro_vertices; i++){
        printf("%d -> ", i);
        
        for(j = 0; j < gr->grau[i]; j++){
            printf("%d", gr->arestas[i][j]);
            if(gr->eh_ponderado){
                printf("[%d]", gr->pesos[i][j]);
            }
            if(j + 1 < gr->grau[i]){
                printf(", ");
            }
        }
        printf("\n");
    }
}