SRC = src
LIB = lib

build b:
	$(MAKE) build --directory=$(SRC) -s

debug dbg d:
	$(MAKE) debug --directory=$(SRC) -s

clean c:
	$(MAKE) clean --directory=$(SRC) -s
	$(MAKE) clean --directory=$(LIB) -s

test t:
	$(MAKE) test --directory=$(LIB) -s
