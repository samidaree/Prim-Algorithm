#ifndef PRIM_HEADER 
    #define PRIM_HEADER
    #ifndef PRIM 
        #define WHERE_PRIM extern 
    #else 
        #define WHERE_PRIM
    #endif

    #define INFINI 1000.0 

    #include "graph.h"
    
    /**
     * @brief affiche l'arbre couvrant de plus de petit poids 
     * 
     * @param g graphe valué et non orienté g 
     */

    WHERE_PRIM void prim (Graph *g); 
    /**
     * @brief Retourne le sommet de poids m
     * 
     * @param nbSommet ordre du graphe 
     * @param valeur tableau des valeurs minimales pour chaque sommet (indice du tableau)
     * @param marque tableau des sommets deja inclus dans l'arbre couvrant 
     * @return le sommet non visité de poids minimal  
     */
    WHERE_PRIM int choixSommetMin(int nbSommet, int valeur[], int marque[]) ; 

#endif 