/**
 * @file graph.c
 * @author Sami Boufassa
 * @brief implements adjacency matrix of graphs
 */

#define GRAPH 
#include <stdlib.h>
#include <stdio.h>
#include "graph.h"


Graph * createGraph(){
    int u,v,i; 
    Graph *g = malloc (sizeof(Graph)); 

    if (g==NULL){
        printf("Probleme d'allocation mémoire"); 
        exit (EXIT_FAILURE); 
    }

    printf("\n Enter number of nodes and edges :\n"); 
    scanf("%d%d", &g->v, &g->e); 

    // Allocation of first line of adjacency Matrix 
    g->adj = malloc(sizeof(int*) * g->v); 

    // Allocation of v cells for each element of the first line of adjacency Matrix
    for (int i=0; i<g->v; i++)
        g->adj[i] = calloc (sizeof(int) ,g->v); 


    return g ;  
}


void createAdjMatrix(Graph *g){
    printf("Enter node numeros in pair for an edge then the value of the edge\n"); 
    int u, v;
    float edge; 
    for ( int i=0; i<g->e; i++){
        scanf("%d %d %f", &u,&v, &edge); 
        g->adj[u][v] = edge ; 
        g->adj[v][u] = edge;
    }
}

void printMatrix(Graph *g){
    printf("\nLa matrice d'adjacence est : \n");
    for (int i = 0; i<g->v; i++){
        for (int j =0; j<g->v; j++)
            printf("%d", g->adj[i][j]);
        printf("\n"); 
    }
}

void printGraph(Graph *g){
    printf("graph {\n");

    for (int i = 0; i<g->v; i++){
        for (int j =i+1; j<g->v; j++)
            if (g->adj[i][j])
                printf("%d -- %d;\n", i,j);
    }
    printf("}"); 

}

void fileGraph(Graph *g){
    FILE *f = fopen("graph.txt", "w"); 
    fprintf(f,"%s", "graph {\n"); 

    for (int i = 0; i<g->v; i++){
        for (int j =i+1; j<g->v; j++)
            if (g->adj[i][j])
                fprintf(f,"%d -- %d [label =""%d""];\n", i,j,g->adj[i][j]);
    }
    fprintf(f,"%s","}"); 

    char code = fclose(f); 
    if (code == EOF)
        printf("Erreur fermeture fichier"); 
}

void marquerVoisins(Graph *g, int s){
    int * marques = calloc (sizeof(int),g->v); 

    int x,y; 

    marques[s] = 1 ; 
    printf("\n L'ordre de marquage :\n "); 
    printf("%d",s);
    for (x=0; x<g->v;x++){
        if (marques[x])
            for (y=0;y<g->v;y++)
                if (g->adj[x][y]&&!marques[y]){
                        marques[y]=1; 
                        printf("\n%d\t", y);
                }
    }


}