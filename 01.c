#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int V;
    int A;
    int **mat;
} g_matrix;

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

void adicionarAresta(g_list *l, int u, int v);

g_list *matrix2list(g_matrix *m);
g_matrix *list2matrix(g_list *l);

int main()
{

    return 0;
}

void adicionarAresta(g_list *l, int u, int v)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));

    n->v = v;
    n->next = l->adj[u];
    l->adj[u] = n;
    l->A++;
}

g_list *matrix2list(g_matrix *m)
{
    g_list *lista = (g_list *)malloc(sizeof(g_list));

    lista->A = 0;
    lista->V = m->V;
    lista->adj = (link *)calloc(lista->V, sizeof(link));

    for (int i = 0; i < m->V; i++)
        for (int j = 0; j < m->V; j++)
            if (m->mat[i][j])
                adicionarAresta(lista, i, j);

    return lista;
}

g_matrix *list2matrix(g_list *l)
{
    g_matrix *matriz = (g_matrix *)malloc(sizeof(g_matrix));

    matriz->A = l->A;
    matriz->V = l->V;

    matriz->mat = (int **)malloc(l->V * sizeof(int *));
    for (int i = 0; i < l->V; i++)
        matriz->mat[i] = (int *)calloc(l->V, sizeof(int));

    for (int i = 0; i < l->V; i++)
        for (link j = l->adj[i]; j; j = j->next)
            matriz->mat[i][j->v] = 1;

    return matriz;
}