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
 
struct stack		{

	int array[100];
	int sp;

};
typedef struct stack Stack;


Stack* initStack();
void push( Stack*, int );
void pop( Stack* );
int peek( Stack* );
int contains( Stack*, int );