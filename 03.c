#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int V;
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
    link *adj;
} g_list;

int isEqual(g_list *l, g_matrix *m)
{
    if (l->V != m->V)
        return 0;
    if (l && !m || !l && m)
        return 0;
    if (!l && !m)
        return 1;

    for (int i = 0; i < m->V; i++)
    {
        link k = l->adj[i];

        for (int j = 0; j < m->V; j++)
            if (m->mat[i][j])
                if (k && k->v == j)
                    k = k->next;
                else
                    return 0;

        if (k)
            return 0;
    }

    return 1;
}