#include "graph.h"
#include "prim.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
     Graph *g = createGraph(); 
    createAdjMatrix(g); 
    printGraph(g);
    fileGraph(g); 
    printMatrix(g); 
    prim(g); 
    return EXIT_SUCCESS; 
}