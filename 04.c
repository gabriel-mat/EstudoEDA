#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct node *link;

struct node
{
    int v;
    link next;
};

typedef struct
{
    int V;
    int A;
    link *adj;
} g_list;

int tamanho(g_list *g, int origem, int destino)
{
    int vertice;
    int *visitados = (int *)calloc(g->V, sizeof(int));
    int *distancias = (int *)calloc(g->V, sizeof(int));

    fila f;
    incializa_fila(&f);
    insere_fila(&f, origem);
    visitados[origem] = 1;

    while (!fila_vazia(&f))
    {
        vertice = remove_fila(&f);

        for (link l = g->adj[vertice]; l; l = l->next)
        {
            if (visitados[l->v])
                continue;

            distancias[l->v] = distancias[vertice] + 1;
            visitados[l->v] = 1;
            insere_fila(&f, l->v);
        }
    }

    int tamanho = visitados[destino] ? distancias[destino] : -1;

    destroi_fila(&f);
    free(visitados);
    free(distancias);

    return tamanho;
}