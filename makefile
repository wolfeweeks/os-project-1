
GCC = gcc #an unnecessary pattern
.SUFFIXES: #none for this project (no object files)

chain: simpleChain.c
	$(GCC) simpleChain.c -o chain

clean:
	rm -rf *.o