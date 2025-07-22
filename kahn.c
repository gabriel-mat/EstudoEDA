#include <stdlib.h>

int *kahn(grafo *g){
    int u, counter;
    int *graus = (int *)calloc(g->V , sizeof(int));
    int *ordem = (int *)malloc(g->V * sizeof(int));

    for(int i = 0; i < g->V; i++)
        for(link l = g->adj[i]; l; l = l->next)
            graus[l->v]++;

    fila f;
    inicializa_fila(&f);

    for(int i = 0; i < g->V; i++)
        if(!graus[i])
            insere_fila(&f, i);

    counter = 0;

    while(!fila_vazia(&f)){
        u = remove_fila(&f);
        ordem[counter++] = u;

        for(link l = g->adj[u]; l; l = l-> next){
            graus[l->v]--;

            if(!graus[l->v])
                insere_fila(&f, l->v);
        }
    }

    free(graus);

    if(counter < g->V){
        free(ordem);
        return NULL;
    }

    return ordem;
}