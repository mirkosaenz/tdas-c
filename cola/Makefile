CC=gcc
CFLAGS=-c
OUTPUT=cola_tests
DEPENDENCIES=cola.o cola_tests.o utils.o
FILES=$(DEPENDENCIES) $(OUTPUT)

$(OUTPUT): $(DEPENDENCIES)
	$(CC) $^ -o $(OUTPUT)

cola.o: cola.c
	$(CC) $(CFLAGS) $<

cola_tests.o: cola_tests.c
	$(CC) $(CFLAGS) $<

utils.o: ../test_utils/utils.c
	$(CC) $(CFLAGS) $<

clean:
	rm -rf $(FILES)