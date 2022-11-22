
CC = gcc

AR = ar -rcs

BASE = basicClassification.o

RECURSION = advancedClassificationRecursion.o

LOOPS = advancedClassificationLoop.o

FLAGS = -Wall -g

MAIN = main.o

PIC = -fPIC

all: maindrec maindloop mains libclassloops.a main.o

maindrec: $(MAIN) libclassrec.so
	$(CC) $(FLAGS) main.o ./libclassrec.so -o maindrec
	
maindloop: main.o libclassloops.so
	$(CC) $(FLAGS) main.o ./libclassloops.so -o maindloop

mains: main.o libclassrec.a
	$(CC) $(FLAGS) main.o libclassrec.a -o mains
loops: libclassloops.a

recursives: libclassrec.a

recursived: libclassrec.so

loopd: libclassloops.so

libclassloops.so: $(BASE) $(LOOPS)
	$(CC) $(FLAGS) -shared -o libclassloops.so $(BASE) $(LOOPS)

libclassrec.so: $(BASE) $(RECURSION)
	$(CC) $(FLAGS) -shared  -o libclassrec.so $(BASE) $(RECURSION)

libclassrec.a: $(BASE) $(RECURSION)
	$(AR) libclassrec.a $(BASE) $(RECURSION)

libclassloops.a: $(BASE) $(LOOPS)
	$(AR) libclassloops.a $(BASE) $(LOOPS)

basicClassification.o: basicClassification.c
	$(CC) $(FLAGS) $(PIC) -c basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c
	$(CC) $(FLAGS) $(PIC) -c advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c
	$(CC) $(FLAGS) $(PIC) -c advancedClassificationRecursion.c

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c

clean:
	rm -f *.a *.so *.o maindloop maindrec mains

.PHONY: clean all