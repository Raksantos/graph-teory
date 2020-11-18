#include <stdio.h>
#include <stdlib.h>

struct adjNode{
    int dest;
    struct adjNode* next;
};

typedef struct adjNode node;

struct adjList{
    struct adjNode *head;
};

typedef struct adjList aList;

struct graph{
    int V;
    aList* array;
};

typedef struct graph Graph;

node* newAdjListNode(int dest)
{
    node* newNode = (node*) malloc(sizeof(node));
    newNode->dest = dest;
    newNode->next = NULL;

    return newNode;
}

Graph* createGraph(int V)
{
    Graph* newGraph = (Graph*) malloc(sizeof(Graph));
    newGraph->V = V;

    newGraph->array = (aList*) malloc(sizeof(aList));

    for(int i = 0; i < V; ++i){
        newGraph->array[i].head = NULL;
    }

    return newGraph;
}

void addEdge(Graph* grafo, int vertice_ini, int vertice_fim)
{
    node* newNode = newAdjListNode(vertice_fim);
    newNode->next = grafo->array[vertice_ini].head;
    grafo->array[vertice_ini].head = newNode;

    newNode = newAdjListNode(vertice_ini); 
    newNode->next = grafo->array[vertice_fim].head; 
    grafo->array[vertice_fim].head = newNode; 
}


void printGraph(Graph* grafo)
{
    int v; 
    for (v = 0; v < grafo->V; ++v) 
    { 
        node* pCrawl = grafo->array[v].head; 
        printf("\n Adjacency list of vertex %d\n head ", v); 
        while (pCrawl) 
        { 
            printf("-> %d", pCrawl->dest); 
            pCrawl = pCrawl->next; 
        } 
        printf("\n"); 
    } 
}

int main(){

    int V, arestas;

    printf('Digite o número de vertices: ');
    scanf('%d', &V);

    printf('Digite o número de arestas: ');
    scanf('%d', &arestas);

    Graph* grafo = createGraph(V);

    int vertice1, vertice2;

    while(arestas >= 0){
        printf('Digite o primeiro vertice: ');
        scanf('%d', &vertice1);

        printf('Digite o segundo vertice: ');
        scanf('%d', &vertice2);

        addEdge(grafo, vertice1, vertice2);
    }

    return 0;
}