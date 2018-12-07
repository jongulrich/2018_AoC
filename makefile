all: 1 2 3
CC=g++
FLAGS=-std=c++11

.PHONY: 1
1:
	$(CC) -o run1a 1a.cpp $(FLAGS)
	$(CC) -o run1b 1b.cpp $(FLAGS) 

.PHONY: 2
2:
	
	$(CC) -o run2 2.cpp $(FLAGS) 
	$(CC) -o run2b 2b.cpp $(FLAGS) 

.PHONY: 3
3:
	
	$(CC) -o run3a 3a.cpp $(FLAGS)

