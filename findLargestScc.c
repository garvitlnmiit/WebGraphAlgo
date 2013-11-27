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
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h" 
#include "Stack.h" 

static int *tempScc1=NULL;
static int *tempScc2=NULL;
static int count=0, max=0;	
 
static void fillOrder(Graph* graph, int v, int *visited, Stack *stack)
{
	Node *ptr=NULL;
	visited[v]=1;
	ptr = graph->array[v].head;
	while(ptr!=NULL)
	{
		if(visited[ptr->dest]==0)
			fillOrder(graph, ptr->dest, visited, stack);
		
		ptr=ptr->next;
	}	
	
	push(stack, v);
}

static Graph* getTranspose(Graph* graph)
{
	int v;
	Node *ptr;
	Graph* revGraph = createGraph(graph->V);	

	for(v=0; v<graph->V; v++)
	{
		ptr = graph->array[v].head;

		while(ptr!=NULL)
		{
			addEdge(revGraph, ptr->dest, v);
			ptr=ptr->next;
		}	
	}
	
	return revGraph;	
}

static void dfsUtil(Graph *graph, int v, int *visited)
{
	visited[v]=1;
	Node *ptr = graph->array[v].head;
	tempScc1[count++]=v;
	while(ptr!=NULL)
	{
		if(visited[ptr->dest]==0)
			dfsUtil(graph, ptr->dest, visited);

		ptr=ptr->next;
	}	
}

static void findSccs(Graph* graph)
{
	int V=graph->V, i;
	int *visited=(int *)malloc(V*sizeof(int));
	//memset(visited, 0, V);
	for(i=0;i<V;i++)
	visited[i]=0;

	Stack *stack=initStack();	

	for(i=0;i<V;i++) 
		if(visited[i]==0)
			fillOrder(graph,i,visited,stack);
	
	Graph *revGraph=getTranspose(graph);

	//printGraph(revGraph);

	for(i=0;i<V;i++)
	visited[i]=0;

	//memset(visited, 0, V);

	while(stack->sp!=-1)
	{
		int v=peek(stack);
		pop(stack);

		if(visited[v]==0)
		{
			count=0;
			tempScc1=(int *)malloc(V*sizeof(int));
			dfsUtil(revGraph,v,visited);

			//for(i=0;i<count;i++)
			//printf("%d ", tempScc1[i]);

			
			if(count>max)
			{
				max=count;
				free(tempScc2);
				tempScc2=tempScc1;
			}
		}
	}
}

extern void longestScc(Graph* graph, int* flagArray)
{
	int i;
	findSccs(graph);
	for(i=0;i<max;i++)
	flagArray[tempScc2[i]]=1;
}
