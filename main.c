#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
	unsigned char buf[8] = {0};
	int nread;
	int i;
	FILE *fd;

	if (argc < 2) {
		puts("Please specify an input file");
	} else if ((fd = fopen(argv[1], "r")) == NULL) {
		puts("Can not open file or file does not exists");
	} else {
		while ((nread = fread(buf, 1, 8, fd)) != 0) {
			for (i=0;i<nread;i++) {
				printf(" %.2x", buf[i]);
			}
			printf("    ");
			for (i=0;i<nread;i++) {
				if (buf[i] != 13 && buf[i] != 12 && buf[i] != 10 && buf[i] != 11)
					printf("%c", buf[i]);
			}
			printf("\n");
		}
	}

	return 0;
}

