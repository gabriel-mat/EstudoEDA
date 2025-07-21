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

void dfs_private(g_list *l, int visitados[], int *ciclico, int vertice)
{
    visitados[vertice] = 1;

    for (link k = l->adj[vertice]; k != NULL; k = k->next)
    {
        if (visitados[k->v] == 0)
            dfs_private(l, visitados, ciclico, k->v);
        else if (visitados[k->v] == 1)
        {
            *ciclico = 1;
            return;
        }
    }

    visitados[vertice] = 2;
}

int dfs(g_list *l)
{
    int ciclico = 0;
    int *visitados = (int *)calloc(l->V, sizeof(int));

    for (int i = 0; i < l->V && !ciclico; i++)
        if (visitados[i] == 0)
            dfs_private(l, visitados, &ciclico, i);

    return ciclico;
}

int isCyclic(g_list *l)
{
    return dfs(l);
}