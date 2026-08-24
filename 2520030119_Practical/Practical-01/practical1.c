#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
int main() {
    char command[100];

    printf("Enter a Linux command: ");
    fgets(command, sizeof(command), stdin);

    // Remove newline character
    command[strcspn(command, "\n")] = '\0';

    pid_t child_pid = fork();

    if (child_pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (child_pid == 0) {
        // Child process
        printf("\nChild Process PID: %d\n", getpid());
        printf("Executing command: %s\n", command);

        execlp(command, command, (char *)NULL);

        // Executes only if execlp fails
        perror("exec failed");
        exit(1);
    }
    else {
        // Parent process
        printf("Parent Process PID: %d\n", getpid());
        printf("Waiting for child process...\n");

        wait(NULL);

        printf("Child process completed.\n");
    }

    return 0;
}
