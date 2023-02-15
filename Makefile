SRC = src
LIB = lib

.PHONY: run
run:
	$(MAKE) --directory=$(SRC);

.PHONY: build
build:
	$(MAKE) build --directory=$(SRC);

.PHONY: test
test:
	$(MAKE) test --directory=$(LIB)

.PHONY: clean
clean:
	$(MAKE) clean --directory=$(LIB)
	$(MAKE) clean --directory=$(SRC)
