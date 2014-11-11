#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include "indexer.h"

int main (int argc, char const *argv[]) {

	struct stat s;

	if (argc < 2) {
		printf("%s\n", "invalid number of arguments");
	}

	if(stat(argv[1], &s) == 0) {
		printf("error - '%s' is not a file or directory\n", argv[1]);
	    return -1;
	}

	FILE *inverted = fopen(argv[1], "r");
	Index *index = load_index(inverted);


	fclose(inverted);
	index_destroy(index);

	return 0;

}
