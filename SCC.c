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

#include<stdio.h>
#include<stdlib.h>
#include "findLargestScc.h"
#include "Stack.h"

void traverse( int* );
void findInTendrils( Graph*, int* );
int checkTubes( Node*, int*, Stack* );
void printDetails( int* );

static int totVert, change;					// total vertices in a graph
static Graph *graph;

int main()		{

	int i, k;
	int *flagArray;
	
	graph = create_graph();
	totVert = graph->V;
	
	flagArray = (int *)calloc(totVert, sizeof(int));
	
	longestScc(graph, flagArray);	
	//printGraph( graph );
	
	for( k=0; k<=totVert/2; k++ )		{
	
		change = 0;
		traverse( flagArray );	
		
		if( change == 0 )
			break;		
		
//		for( i=0; i<totVert; i++ )
//			printf("%d - > %d\n", i, flagArray[i]);
//		printf("\n");
		
	}//End Of Loop
	
	findInTendrils( graph, flagArray );
	
//	for( i=0; i<totVert; i++ )
//		printf("%d - > %d\n", i, flagArray[i]);	

	printDetails( flagArray );
	
	return 0;

}//End Of Main


void traverse( int *arr )		{

	Node *ptr;
	int i;

	for( i=0; i<totVert; i++ )			{
	
		switch( arr[i] )		{
		
			case 1:
			case 2:
				
				ptr = graph->array[i].head;
				
				while( ptr!= NULL )		{
					
					if( arr[ ptr->dest ] == 0 )				{
						arr[ ptr->dest ] = 2;												// 2 => OUT
						change = 1;
					}
					
					ptr = ptr->next;
				
				}//End Of While Loop
				
				break;
			case 0:
			
				ptr = graph->array[i].head;
				
				while( ptr!= NULL )		{
					
					if( arr[ ptr->dest ] == 1 || arr[ ptr->dest ] == 3 )			{
						arr[ i ] = 3;													// 3 => IN
						change = 1;
					}else if( arr[ ptr->dest ] == 2 )				{
						arr[ i ] = 4;													// 4 => TENDRIL
						change = 1;
					}
					
					ptr = ptr->next;
				
				}//End Of While Loop				
			
				break;
			case 3:
			
				ptr = graph->array[i].head;
				
				while( ptr!= NULL )		{
					
					if( arr[ ptr->dest ] == 0 )				{
						arr[ ptr->dest ] = 4;												// 4 => TENDRIL
						change = 1;
					}
					
					ptr = ptr->next;
				
				}//End Of While Loop				
			
				break;				
			case 4:
			
				ptr = graph->array[i].head;
				
				while( ptr!= NULL )		{
					
					if( arr[ ptr->dest ] == 0 )				{
						arr[ ptr->dest ] = 4;												// 4 => TENDRIL
						change = 1;
					}
					
					ptr = ptr->next;
				
				}//End Of While Loop				
			
				break;								
			default:
				break;
				
		}//End Of Switch
	
	}//End Of Loop
	

}//End Of Method



void findInTendrils( Graph *graph, int *flags )			{

	Stack *stck = initStack();
	Stack *temp;
	Node *ptr;
	int i, val, ret;
	
	for( i=0; i<totVert; i++ )			{
	
		if( flags[i] == 3 )			{
		
			ptr = graph->array[i].head;
		
			while( ptr!=NULL )		{
			
				if( flags[ptr->dest] == 4 )		
					push( stck, ptr->dest );

				ptr = ptr->next;
			
			}//End Of Loop
			
		}//End Of IF	
		
	}//End Of Loop
	
	while( stck->sp != -1 )			{
	
		val = peek( stck );
		ptr = graph->array[val].head;
		
		temp = initStack();
		push( temp, val );
		
		ret = checkTubes( ptr, flags, temp );
		if( ret == 1 )
			flags[val] = 5;								// 5 => TUBES
		
		pop( stck );
		pop( temp );
		free( temp );
	
	}//End Of Loop
	
	free( stck );
	
}//End Of Method



int checkTubes( Node *ptr, int *flags, Stack *temp )			{

	int ret = 0;

	while( ptr!=NULL )		{
	
		if( !contains(temp, ptr->dest) && (flags[ptr->dest] == 4 || flags[ptr->dest] == 5) )			{
		
			push( temp, ptr->dest );
			ret = checkTubes( graph->array[ptr->dest].head, flags, temp );
			pop( temp );
			
			if( ret == 1 )
				flags[ptr->dest] = 5;								// 5 => TUBES
			
		}else if( flags[ptr->dest] == 2 )
			return 1;
	
		ptr= ptr->next;
	
	}//End Of Loop
	
	return ret;

}//End Of Method


void printDetails( int *flags )			{

	int i;
	
	printf("\nSCC: \n");
	for( i=0; i<totVert; i++ )
		if( flags[i] == 1 )
			printf("%d ", i);
		
	printf("\n\nOUT: \n");
	for( i=0; i<totVert; i++ )
		if( flags[i] == 2 )
			printf("%d ", i);

	printf("\n\nIN: \n");
	for( i=0; i<totVert; i++ )
		if( flags[i] == 3 )
			printf("%d ", i);

	printf("\n\nTENDRILS: \n");
	for( i=0; i<totVert; i++ )
		if( flags[i] == 4 || flags[i] == 0 )
			printf("%d ", i);

	printf("\n\nTUBE: \n");
	for( i=0; i<totVert; i++ )
		if( flags[i] == 5 )
			printf("%d ", i);			
		
}//End Of Main