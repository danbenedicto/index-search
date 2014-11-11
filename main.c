#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "indexer.h"

int main (int argc, char const *argv[]) {

	if (argc < 2) {
		printf("invalid number of arguments");
	}

	FILE *inverted = fopen(argv[1], "r");

	if(inverted == NULL) {
		printf("error - '%s' is not a file or directory\n", argv[1]);
	    return -1;
	}

	Index *index = load_index(inverted);

	char query[256];

	while (1){
		fgets(query, 256, stdin);
		printf("%s\n", query);
		char* token = strtok(query, " ");
		if (strcmp(token, "sa") == 0){
			while (token != NULL){
				printf("farto %s\n", token);
				token = strtok(NULL, " \n");
				/* insert 'and' function here */
			}
		} else if (strcmp(token, "so") == 0){
			while (token != NULL){
				printf("%s\n", token);
				token = strtok(NULL, " \n");
				/* insert 'or' function here */
			}
		} else if (query[0] == 'q' && query[1] == '\n'){
			break;
		} else {
			printf("error - command not found\n");
		}
		memset(query, 0, sizeof(query));
	}


	fclose(inverted);
	index_destroy(index);

	return 0;

}
