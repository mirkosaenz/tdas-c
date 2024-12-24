CC=gcc
CFLAGS=-c
OUTPUT=arreglo_tests
FILES=arreglo_tests.o arreglo.o arreglo_tests

$(OUTPUT): arreglo_tests.o arreglo.o
	$(CC) $^ -o $(OUTPUT)

arreglo_tests.o: arreglo_tests.c
	$(CC) $(CFLAGS) $<

arreglo.o: arreglo.c
	$(CC) $(CFLAGS) $<

clean:
	rm -rf $(FILES)