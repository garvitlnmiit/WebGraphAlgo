/**
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it.
 * This code is distributed in the hope that it will be useful.
 *
 * Developed By Students Of <The LNM Institute Of Information Technology, Jaipur>.
 *	- Garvit Sharma
 *	- Siddhant Goenka
 * 
 *
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "Graph.h" 
 
// A utility function to create a new adjacency list node
static struct AdjListNode* newAdjListNode(int dest)
{
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
 
// A utility function that creates a graph of V vertices
extern Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
 
    // Create an array of adjacency lists.  Size of array will be V
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
 
     // Initialize each adjacency list as empty by making head as NULL
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;
 
    return graph;
}
 
// Adds an edge to an undirected graph
extern void addEdge(struct Graph* graph, int src, int dest)
{
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
 
    // Since graph is undirected, add an edge from dest to src also
/*
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
*/
}
 
// A utility function to print the adjacenncy list representation of graph
extern void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n\n\n");
    }
}
 
// Driver program to test above functions
extern Graph* create_graph()
{
    // create the graph given in above fugure
    int V = 16;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 11);
	addEdge(graph, 0, 2);					// ---> Loop
    addEdge(graph, 1, 8);
    addEdge(graph, 2, 0);
	addEdge(graph, 2, 15);
    addEdge(graph, 3, 1);
	addEdge(graph, 3, 7);					//--> Bigger SCC
    addEdge(graph, 4, 1);
	addEdge(graph, 4, 13);
	addEdge(graph, 5, 9);
	addEdge(graph, 7, 2);
	addEdge(graph, 9, 6);
	addEdge(graph, 9, 7);
	addEdge(graph, 9, 10);
	addEdge(graph, 10, 4);
	addEdge(graph, 11, 3);
	addEdge(graph, 12, 7);
	addEdge(graph, 13, 10);
	addEdge(graph, 14, 1);
	addEdge(graph, 15, 11);
	
	addEdge(graph, 10, 13);
	addEdge(graph, 13, 4);
 
    return graph;
}
