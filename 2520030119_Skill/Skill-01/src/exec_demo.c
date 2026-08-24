#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Before exec()\n");
    printf("PID: %d\n", getpid());

    execlp("ls", "ls", "-l", NULL);

    perror("exec failed");

    return 1;
}
