#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename ...\n", argv[0]);
        return 1;
    }

    // Get the PATH environment variable
    char *path = getenv("PATH");
    if (path == NULL) {
        printf("PATH environment variable not found.\n");
        return 1;
    }

    // Tokenize the PATH variable to get individual directories
    char *pathToken = strtok(path, ":");
    while (pathToken != NULL) {
        // Check if the file exists in the current directory
        for (int i = 1; i < argc; i++) {
            char filePath[MAX_PATH_LENGTH];
            snprintf(filePath, sizeof(filePath), "%s/%s", pathToken, argv[i]);

            FILE *file = fopen(filePath, "r");
            if (file != NULL) {
                printf("%s\n", filePath);
                fclose(file);
            }
        }

        // Move to the next directory in the PATH
        pathToken = strtok(NULL, ":");
    }

    return 0;
}