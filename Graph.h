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

struct AdjListNode		{ 

    int dest;
    struct AdjListNode* next;
	
};
typedef struct AdjListNode Node;
 
 
struct AdjList		{

	struct AdjListNode *head; 

};


struct Graph		{

	int V;
    struct AdjList* array;
	
};
typedef struct Graph Graph;

void addEdge(Graph*, int, int);
Graph* createGraph(int);
Graph* create_graph();
void printGraph(struct Graph*);