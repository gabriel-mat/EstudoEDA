#include <limits.h>
#include <stdlib.h>

void dijkstra(grafo* g, int origem, int distancias[]) {
    fila f;
    incializa_fila(&f);
    
    int *processado = (int *)calloc(g->V, sizeof(int));
    
    for (int i = 0; i < g->num_vertices; i++)
        distancias[i] = INT_MAX;

    inserir_fila(&fila, origem, 0);
    distancias[origem] = 0;

    while (!vazia(&fila)) {
        int min = extrai_min(&fila);

        if (processado[min])
            continue;
        
        processado[min] = 1;

        for (link n = g->adj[min]; n != NULL; n = n->next) {
            if (distancias[n->data] > distancias[min] + n->peso) {
                distancias[n->data] = distancias[min] + n->peso;
                inserir_fila(fila, n->data, distancias[n->data]);
            }
        }
    }
}