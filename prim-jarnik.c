#include <stdlib.h>
#include <limits.h>

int *prim_jarnik(grafo* g, int origem){
    fila f;
    int *keys = (int *)malloc(g->V * sizeof(int));
    int *visitados = (int *)calloc(g->V, sizeof(int));

    for (int i = 0; i < g->V; i++)
        keys[i] = INT_MAX;

    inserir_fila(&fila, origem, 0);
    keys[origem] = 0;

    while(!vazia(fila)){
        int min = extrai_min(&f);
        vis[min] = 1;

        for(link n = g->adj[min]; n != NULL; n = n->next){
            if(!vis[n->data] && keys[n->data] > n->peso){
                keys[n->data] = n->peso;
                inserir_fila(&fila, n->data, n->peso);
            }
        }
    }

    return keys;
}
