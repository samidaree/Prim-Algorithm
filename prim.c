#include <stdlib.h>
#include <stdio.h>
#include "prim.h"
#include "graph.h"
#define PRIM 

int choixSommetMin(int nbSommet, int valeur[], int marque[]){
    int minimum = INFINI; 
    int sommet ; 
    for (int i = 0; i<nbSommet; i++){
        if (marque[i]==0 && valeur[i]<minimum){
            sommet = i ; 
            minimum = valeur[i]; 
        }
    }
    return sommet; 
}

void prim(Graph *g){
    int parent[g->v];
    int marque[g->v]; 
    int valeurs[g->v]; 

    for (int i =0; i<g->v; i++){
        marque[i] = 0; 
        valeurs[i] = INFINI; 
    }

    parent [0]= -1; 
    valeurs[0]= 0; 

    for (int i =0; i<g->v-1; i++){
        int x = choixSommetMin(g->v,valeurs,marque); 
        marque[x] = 1 ; 

        for (int j =0; j<g->v; j++){
            if(g->adj[x][j]!=0 && marque[j]==0 && g->adj[x][j]<valeurs[j]){
                valeurs[j] = g->adj[x][j]; 
                parent[j] = x; 
            }
        }
    }

    FILE * fic = fopen("arbre.txt", "w"); 
    fprintf(fic,"digraph BST {\n");
    for (int i =1; i<g->v; i++){
        printf("%d -> %d; poids = %d\n ", parent[i],i,g->adj[parent[i]][i]); 
        fprintf(fic,"%d -> %d [label = ""%d""]; \n ", parent[i],i,g->adj[parent[i]][i]); 
    }
    fprintf(fic, "}"); 
} 