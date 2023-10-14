#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split(char *str, char sep) {
    int len = strlen(str);
    int c = 0;
    int *count = &c;
    int i = 0;

    // Count the number of substrings
    while (i < len) {
        // Skip leading separators
        while (i < len && str[i] == sep)
            i++;

        if (i == len) {
            // If we reached the end of the string, break
            break;
        }

        // Move to the end of the current segment
        while (i < len && str[i] != sep)
            i++;

        // Count the start of a new segment
        (*count)++;
    }

    // Allocate an array to contain the substrings
    char **result = (char **)malloc(sizeof(char *) * (*count + 1));
    if (result == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    // Reset count for substring indexing
    *count = 0;
    i = 0;

    // Populate the array with substrings
    while (i < len) {
        // Skip leading separators
        while (i < len && str[i] == sep)
            i++;

        if (i == len) {
            // If we reached the end of the string, break
            break;
        }

        // Find the end of the current segment
        int start = i;
        while (i < len && str[i] != sep)
            i++;

        // Allocate memory for the substring
        result[*count] = (char *)malloc(i - start + 1);
        if (result[*count] == NULL) {
            perror("malloc failed");
            exit(EXIT_FAILURE);
        }

        // Copy the substring into the array
        strncpy(result[*count], str + start, i - start);
        result[*count][i - start] = '\0';  // Null-terminate the substring

        // Move to the next substring
        (*count)++;
    }

    // Set the last pointer to NULL
    result[*count] = NULL;

    return result;
}

// Free the memory allocated for substrings
void free_substrings(char **substrings, int count) {
    for (int i = 0; i < count; i++) {
        free(substrings[i]);
    }
    free(substrings);
}

int main(void) {
    char *name = "omar is cool yh";
    char sep = ' ';

    char **result = split(name, sep);

    if (result != NULL) {
        for (int i = 0; result[i] != NULL; i++) {
            printf("Token %d: %s\n", i, result[i]);
            free(result[i]);  // Only free if not NULL
        }

        free(result);
    }

    return 0;
}
