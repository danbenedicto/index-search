all: search

index: index_main.c indexer.c indexer.h
	gcc -Wall -g -o index index_main.c indexer.c

search: main.c indexer.c indexer.h
	gcc -Wall -g -o search main.c indexer.c

clean:
	rm -f index
	rm -fr index.dSYM
	rm -f search
	rm -fr search.dSYM
	rm -f *.tgz
