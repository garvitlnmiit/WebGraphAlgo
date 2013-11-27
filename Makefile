 #
 # DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 #
 # This code is free software; you can redistribute it.
 # This code is distributed in the hope that it will be useful.
 #
 # Developed By Students Of <The LNM Institute Of Information Technology, Jaipur>.
 #	- Garvit Sharma
 #	- Siddhant Goenka
 # 
 #
 #
 
outputScc: findLargestScc.o Stack.o Graph.o SCC.o
		gcc findLargestScc.o Stack.o SCC.o Graph.o -o outputScc

Graph.o: Graph.c Graph.h
	  gcc -c Graph.c	

SCC.o: SCC.c Graph.h Stack.h
	gcc -c SCC.c	

findLargestScc.o: findLargestScc.c findLargestScc.h
			gcc -c findLargestScc.c

Stack.o: Stack.c Stack.h
	 gcc -c Stack.c	
