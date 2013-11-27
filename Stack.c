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
#include <string.h>
#include "Stack.h"


extern Stack* initStack()		{

	Stack *ptr = (Stack*)malloc( sizeof(Stack) );
	memset( ptr, 0, sizeof(ptr) );

	ptr->sp = -1;
	
	return ptr;

}//End Of Method


extern void push( Stack *ptr , int val )		{

	if( ptr->sp!= 100 )			{
		(ptr->sp)++;
		ptr->array[ptr->sp] = val;
	}else
		printf("Stack Full\n");
		
}//End Of Method


extern void pop( Stack *ptr )		{

	if( ptr->sp != -1 )		{
		ptr->array[ptr->sp] = 0;	
		(ptr->sp)--;
	}else
		printf("Empty Stack\n");
	
}//End Of Method


extern int peek( Stack *ptr )		{

	if( ptr->sp != -1 )
		return ptr->array[ptr->sp];
	else
		return -1;

}//End Of Method



extern int contains( Stack *ptr, int val )		{

	int i;

	for( i=0; i<=ptr->sp; i++ )
		if( ptr->array[i] == val )
			return 1;

	return 0;
			
}//End Of Method