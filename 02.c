#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    return 0;
}

int dfs_private(g_list *g, int *visitados, int v, int cor)
{
    visitados[v] = cor;

    for (link l = g->adj[v]; l != NULL; l = l->next)
        if (visitados[l->v] == cor || visitados[l->v] == 2 && !dfs_private(g, visitados, l->v, 1 - cor))
            return 0;
    return 1;
}

int dfs(g_list *g)
{
    /*
    0: branco
    1: preto
    2: nao visitado
    */

    int retorno = 1;
    int *visitados = (int *)malloc(g->V * sizeof(int));

    for (int i = 0; i < g->V; i++)
        visitados[i] = 2;

    for (int i = 0; i < g->V; i++)
        if (visitados[i] == 2 && !dfs_private(g, visitados, i, 0))
        {
            retorno = 0;
            break;
        }

    free(visitados);
    return retorno;
}

int bipartido(g_list *g)
{
    return dfs(g);
}