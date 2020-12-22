#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

struct grafo{
    int eh_ponderado;
    int nro_vertices;
    int grau_max;
    int** arestas;
    int** pesos;
    int* grau;
};

Grafo *cria_grafo(int nro_vertices, int grau_max, int eh_ponderado){
    Grafo *gr = (Grafo*) malloc(sizeof(struct grafo));

    if(gr != NULL){
        int i, j;
        gr->nro_vertices = nro_vertices;
        gr->grau_max = grau_max;
        gr->eh_ponderado = eh_ponderado;

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

int procuraMenorDistancia(int *dist, int *visitado, int NV){
    int i, menor = -1, primeiro = 1;
    for(i = 0; i < NV; i++){
        if(dist[i] >= 0 && visitado[i] == 0){
            if(primeiro){
                menor = i;
                primeiro = 0;
            }else{
                if(dist[menor] > dist[i]){
                    menor = i;
                }
            }
        }
    }

    return menor;
}

void dijkstra(Grafo *gr, int inicial, int *ant, int *dist){
    int i, cont, NV, ind, *visitado, u;

    cont = NV = gr->nro_vertices;

    visitado = (int*) malloc(NV * sizeof(int));

    for(i = 0; i < NV; i++){
        ant[i] = -1;
        dist[i] = -1;
        visitado[i] = 0;
    }

    dist[inicial] = 0;

    while(cont > 0){
        u = procuraMenorDistancia(dist, visitado, NV);

        if(u == -1){
            break;
        }

        visitado[u] = 1;
        cont--;

        for(i = 0; i < gr->grau[u]; i++){
            ind = gr->arestas[u][i];
            if(dist[ind] < 0){
                dist[ind] = dist[u] + gr->pesos[u][i];

                ant[ind] = u;
            }else{
                if(dist[ind] > dist[u] + gr->pesos[u][i]){
                    dist[ind] = dist[u] + gr->pesos[u][i];

                    ant[ind] = u;
                }
            }
        }
    }

    free(visitado);
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

int main(){
    int i, eh_digrafo = 0, numero_vertices = 6, grau_maximo = 4, eh_ponderado = 1;
    Grafo *gr = cria_grafo(numero_vertices, grau_maximo, eh_ponderado);
    
    insereAresta(gr, 0, 1, eh_digrafo, 1);
    insereAresta(gr, 0, 2, eh_digrafo, 9);
    insereAresta(gr, 0, 5, eh_digrafo, 14);
    insereAresta(gr, 1, 2, eh_digrafo, 10);
    insereAresta(gr, 1, 3, eh_digrafo, 15);
    insereAresta(gr, 3, 2, eh_digrafo, 11);
    insereAresta(gr, 3, 4, eh_digrafo, 6);
    insereAresta(gr, 4, 5, eh_digrafo, 9);
    insereAresta(gr, 2, 5, eh_digrafo, 2);

    int ant[numero_vertices];
    int dist[numero_vertices];
    int origem = 2, objetivo = 4, contador = numero_vertices - 1;

    for(i = 0; i < 6; i++){
        ant[i] = -1;
    }

    dijkstra(gr, origem, ant, dist);

    int caminho[numero_vertices];
    for(i = 0; i < 6; i++){
        caminho[i] = -1;
    }

    printf("%d ->", origem);

    while(objetivo != origem){
        caminho[contador] = objetivo;
        objetivo = ant[objetivo];
        contador--;
    }

    for(i = 0; i < 6; i++){
        if(caminho[i] != -1){
            printf(" %d", caminho[i]);
            if(i + 1 != 6){
                printf(" ->");   
            }
        }
    }

    libera_grafo(gr);

    return 0;
}