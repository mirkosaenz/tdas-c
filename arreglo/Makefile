CC=gcc
CFLAGS=-c
OUTPUT=arreglo_tests
DEPENDENCIES=arreglo_tests.o arreglo.o utils.o
FILES=arreglo_tests.o arreglo.o arreglo_tests utils.o

$(OUTPUT): $(DEPENDENCIES)
	$(CC) $^ -o $(OUTPUT)

utils.o: ../test_utils/utils.c
	$(CC) $(CFLAGS) $<

arreglo_tests.o: arreglo_tests.c
	$(CC) $(CFLAGS) $<

arreglo.o: arreglo.c
	$(CC) $(CFLAGS) $<

clean:
	rm -rf $(FILES)