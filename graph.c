#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

struct grafo{
    int eh_ponderado;
    int nro_vertices;
    int grau_max;
    int** arestas;
    float** pesos;
    int* grau;
};

Grafo *cria_grafo(int nro_vertices, int grau_max, int eh_ponderado){
    Grafo *gr = (Grafo*) malloc(sizeof(struct grafo));

    if(gr != NULL){
        int i;
        gr->nro_vertices = nro_vertices;
        gr->grau_max = grau_max;
        gr->eh_ponderado = eh_ponderado;
        gr->grau = (int*) calloc(nro_vertices, sizeof(int));
        gr->arestas = (int**)malloc(nro_vertices*sizeof(int*));

        for(i = 0; i < nro_vertices; i++){
            gr->arestas[i] = (int*)malloc(grau_max*sizeof(int));

            if(gr->eh_ponderado){
                gr->pesos = (float**) malloc(grau_max*sizeof(float));

                for(i = 0; i < nro_vertices; i++){
                    gr->pesos[i] = (float*)malloc(grau_max*sizeof(float));
                }
            }
        }
    }

    return gr;
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

int insereAresta(Grafo* gr, int origem, int destino, int eh_digrafo, float peso){
    if(gr == NULL) return 0;

    if(origem < 0 || origem >= gr->nro_vertices) return 0;

    if(destino < 0 || destino >= gr->nro_vertices) return 0;

    gr->arestas[origem][gr->grau[origem]] = destino;

    if(gr->eh_ponderado){
        gr->pesos[origem][gr->grau[origem]] = peso;
    }

    gr->grau[origem]++;

    if(eh_digrafo == 0){
        insereAresta(gr, destino, origem, 1, peso);
    }

    return 1;
}

int removeAresta(Grafo* gr, int origem, int destino, int eh_digrafo){
    if(gr == NULL) return 0;

    if(origem < 0 || origem >= gr->nro_vertices) return 0;

    if(destino < 0 || destino >= gr->nro_vertices) return 0;

    int i = 0;

    while(i < gr->grau[origem] && gr->arestas[origem][i] != destino){
        i++;
    }

    if(i == gr->grau[origem]){
        return 0;
    }

    gr->grau[origem]--;
    gr->arestas[origem][i] = gr->arestas[origem][gr->grau[origem]];
    if(gr->eh_ponderado){
        gr->pesos[origem][i] = gr->pesos[origem][gr->grau[origem]];
    }

    if(eh_digrafo == 0){
        removeAresta(gr, destino, origem, 1);
    }

    return 1;
}

void printaGrafo(Grafo *gr, int nro_vertices){
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