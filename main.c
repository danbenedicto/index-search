#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include "indexer.h"

int main (int argc, char const *argv[]) {

	if (argc < 2) {
		printf("invalid number of arguments");
	}

	if(fopen(argv[1], "r") == NULL) {
		printf("error - '%s' is not a file or directory\n", argv[1]);
	    return -1;
	}

	FILE *inverted = fopen(argv[1], "r");
	//Index *index = load_index(inverted);

	char query[256];

	while (strcmp(&query[0],"q") != 0){
		memset(&query[256], 0, sizeof(query));
		scanf("%s", query);
		char* token = strtok(query, " ");
		if (strcmp(token, "sa") == 0){
			while (strcmp(token, NULL) != 0){
				token = strtok(query, " ");
				/* insert 'and' function here */
			}
		} else if (strcmp(token, "so") == 0){
			while (strcmp(token, NULL) != 0){
				token = strtok(query, " ");
				/* insert 'or' function here */
			}
		} else {
			printf("error - command not found");
		}
	}


	fclose(inverted);
	//index_destroy(index);

	return 0;

}
