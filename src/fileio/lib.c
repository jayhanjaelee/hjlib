/**
 * @file lib.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-02-26 10:15
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileio/lib.h"

int read_file(char *filename) {
    FILE *fp = fopen(filename, "r");
    char buffer[BUFSIZ];

    if (fp == NULL) {
        perror("Error opening file.");
        return EXIT_FAILURE;
    }

    // 1024 bytes 씩 읽기 .
    while (fgets(buffer, BUFSIZ, fp) != NULL) {
        printf("%s", buffer);
    }
    printf("\n");

    fclose(fp);

    return EXIT_SUCCESS;
}

int write_file(char *filename, char *body) {
    FILE *fp = fopen(filename, "w");
    fwrite(body, sizeof(char), strlen(body+1), fp);
    fclose(fp);

    return EXIT_SUCCESS;
}

int delete_file(char *filename) {
    // success
    if (remove(filename) == 0) {
        printf("Files %s deleted successfully\n", filename);
    // fail
    } else {
        printf("Error: Unable to delete the file.\n");
        perror("Error details");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
