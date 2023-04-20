#ifndef GRAPH_HEADER
    #define GRAPH_HEADER 

    #ifndef GRAPH 
        #define WHERE_GRAPH extern 
    #else  
        #define WHERE_GRAPH 

    #endif 

    /**
     * @struct Graph 
     * a graph with v verteces, e edges and its adjacency matrix 
     */
    typedef struct graph {
        /**
         * @var v number of verteces 
         */
        int v; 

        /**
         * @var e number of edges 
         */
        int e; 

        /**
         * @var adj adjacency matrix  
         */
        int **adj ; 
    } Graph ;

    /**
     * @brief Allocates memory for a graph and its adjacency matrix 
     * @return a graph g with uninitialized adjacency matrix 
     */
    WHERE_GRAPH Graph * createGraph(); 

    /**
     * @brief Ask users adjacents nodes 
     * @param g a graph with uninitialized adjacency matrix 
     * @bug segmentation fault if user enter node number not between 0 and v-1 included
     */
    WHERE_GRAPH void createAdjMatrix(Graph * g); 

    /**
     * @brief print the adjacency matrix of the graph  
     * @param g a graph with initialized adjacency matrix 
     */

    WHERE_GRAPH void printMatrix(Graph *g); 

    /**
     * @brief print the graph in the format of GraphViz
     * @param g a simple graph with initialized adjacency matrix 
     */
    WHERE_GRAPH void printGraph (Graph *g); 

    /**
     * @brief create a graph.txt file and write the graph in the format of GraphViz 
     * 
     * @param g a simple graph with initialized adjacency matrix 
     */
    WHERE_GRAPH void fileGraph (Graph*g); 
    /**
     * @brief Marks adjacents verteces starting from a reference vertex
     * 
     * @param g a graph with initialized adjacency matrix
     * @param s number of the reference vertex 
     */
    WHERE_GRAPH void marquerVoisins(Graph * g, int s); 

#endif 