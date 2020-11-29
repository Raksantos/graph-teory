typedef struct grafo Grafo;

Grafo *cria_grafo(int nro_vertices, int grau_max, int eh_ponderado);
int removeAresta(Grafo* gr, int origem, int destino, int eh_digrafo);
int insereAresta(Grafo* gr, int origem, int destino, int eh_digrafo, int peso);
void libera_grafo(Grafo *gr);
void printaGrafo(Grafo *gr, int nro_vertices);