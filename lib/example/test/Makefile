FLAGS = -Wall -Werror -Wfatal-errors

.PHONY: test
test: test.o
	./test.o 

test.o: test.c
	gcc $(FLAGS) test.c -o test.o

.PHONY: clean
clean:
	rm -rf test.o
