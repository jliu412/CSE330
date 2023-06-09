EXEC = run
CC = g++ -O3
CFLAGS = -c -Wall

$(EXEC) : Main.o BinarySearchTree.o PlaneLandingSystem.o
	$(CC) -o $(EXEC) Main.o BinarySearchTree.o PlaneLandingSystem.o

Main.o : Main.cpp BinarySearchTree.h PlaneLandingSystem.h
	$(CC) $(CFLAGS) Main.cpp

BinarySearchTree.o : BinarySearchTree.cpp BinarySearchTree.h
	$(CC) $(CFLAGS) BinarySearchTree.cpp

PlaneLandingSystem.o : PlaneLandingSystem.cpp BinarySearchTree.h PlaneLandingSystem.h
	$(CC) $(CFLAGS) PlaneLandingSystem.cpp

clean :
	rm *.o