#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    char input[BUFFER_SIZE];
    int position;

    printf("Simple Shell Interactive Loop\n");
    printf("Type 'exit' to quit.\n\n");

    while (1) {
        printf("myshell> ");
        fflush(stdout);

        if (fgets(input, BUFFER_SIZE, stdin) == NULL) {
            printf("\nExiting shell...\n");
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0) {
            printf("Exiting shell...\n");
            break;
        }

        if (strlen(input) == 0) {
            continue;
        }

        printf("You entered: %s\n", input);
    }

    return 0;
}
