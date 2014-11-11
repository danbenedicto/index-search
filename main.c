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
	scanf("%s", query);

	while (1){
		memset(&query[0], 0, sizeof(query));
		scanf("%s", query);
		char* token = strtok(query, " ");
		if (strcmp(token, "sa") == 0){
			while (stoken != NULL){
				token = strtok(NULL, " ");
				/* insert 'and' function here */
				break;
			}
		} else if (strcmp(token, "so") == 0){
			while (token != NULL){
				token = strtok(NULL, " ");
				/* insert 'or' function here */
				break;
			}
		} else if (strcmp(&query[0],"q") == 0){
			break;
		} else {
			printf("error - command not found");
			break;
		}
	}


	fclose(inverted);
	//index_destroy(index);

	return 0;

}
