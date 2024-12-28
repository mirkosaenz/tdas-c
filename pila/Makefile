CC=gcc
CFLAGS=-c
OUTPUT=pilaTests
DEPENDENCIES=utils.o pila.o pila_tests.o arreglo.o
FILES=utils.o pila.o pila_tests.o arreglo.o pilaTests

$(OUTPUT): $(DEPENDENCIES)
	$(CC) $^ -o $(OUTPUT)

pila.o: pila.c
	$(CC) $(CFLAGS) $<

pila_tests.o: pila_tests.c
	$(CC) $(CFLAGS) $<

utils.o: ../test_utils/utils.c
	$(CC) $(CFLAGS) $<

arreglo.o: ../arreglo/arreglo.c
	$(CC) $(CFLAGS) $<

clean:
	rm -rf $(FILES)