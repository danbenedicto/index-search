#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include "indexer.h"

int main (int argc, char const *argv[]) {

	struct stat s;

	if (argc < 2) {
		printf("invalid number of arguments");
	}

	if(stat(argv[1], &s) == 0) {
		printf("error - '%s' is not a file or directory\n", argv[1]);
	    return -1;
	}

	FILE *inverted = fopen(argv[1], "r");
	Index *index = load_index(inverted);

	char query[256];

	do{
		query = NULL;
		scanf("%s", query);
		char* token = strtok(query, " ");
		if (token == 'sa'){
			while (token != NULL){
				token = strtok(query, " ");
				/* insert 'and' function here */
			}
		} else if (token = 'so'){
			while (token != NULL){
				token = strtok(query, " ");
				/* insert 'or' function here */
			}
		} else {
			printf("error - command not found");
		}
	}while(query != 'q')


	fclose(inverted);
	index_destroy(index);

	return 0;

}
