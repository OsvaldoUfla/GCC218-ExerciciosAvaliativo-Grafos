

#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int bool1;
typedef int TIPOPESO;

#define BRANCO 0
#define AMARELO 1
#define VERMELHO 2

typedef struct adjacencia
{
    int vertice;
    TIPOPESO PESO;
    struct adjacencia *prox;    
}ADJACENCIA;

typedef struct vertice
{
    ADJACENCIA *cab;
}VERTICE;

typedef struct grafo
{
    int vertices;
    int arestas;
    VERTICE * adj;
}GRAFO;

void profundidade(GRAFO *g)
{
    int cor[g->vertices];

    int u;
    for(int u = 0 ; u < g-> vertices ;u++)
    {
        cor[u] = BRANCO;
    }
    for(int u = 0 ; u < g->vertices ;u++)
    {
        if(cor[u] == BRANCO ; u++)
            visitaP(g, u, cor);
    }
}

void visitaP(GRAFO *g, int u, int *cor)
{
    cor[u] = AMARELO;
    ADJACENCIA *v = g->adj[u].cab;
    while(v)
    {
        if(cor[v->vertice] == BRANCO)
            visitaP(g, v->vertice, cor);
        v = v -> prox;
    }
    cor[u] = VERMELHO;
}