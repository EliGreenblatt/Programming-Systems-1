
CC = gcc

AR = ar -rcs

BASE = basicClassification.o

RECURSION = advancedClassificationRecursion.o

LOOPS = advancedClassificationLoop.o

FLAGS = -Wall -g

MAIN = main.o

PIC = -fPIC

all: maindrec maindloop mains libclassloops.a

maindrec: $(MAIN) libclassrec.so
	$(CC) $(FLAGS) -o maindrec $(MAIN) libclassrec.so
	
maindloop: main.o libclassloops.so
	$(CC) $(FLAGS) -o maindloop $(MAIN) libclassloops.so

mains: main.o libclassrec.a

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

$(MAIN): main.c NumClass.h
	$(CC) $(FLAGS) -c main.c

clean:
	rm -f *.a *.so *.o maindloop maindrec mains