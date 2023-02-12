SRC = src/main.c
TGT = bin/main.o

FLAGS = -Wall -Werror -Wfatal-errors

run: $(TGT)
	./$(TGT)

build: $(TGT)

test:
	$(MAKE) test --directory=lib

$(TGT): $(SRC)
	gcc -o $@ $^ $(FLAGS)

clean:
	rm -f bin/*.o;
	$(MAKE) clean --directory=lib