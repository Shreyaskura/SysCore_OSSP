#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    struct termios old_terminal, new_terminal;
    char buffer[BUFFER_SIZE];
    int position = 0;
    char ch;

    tcgetattr(STDIN_FILENO, &old_terminal);
    new_terminal = old_terminal;

    new_terminal.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_terminal);

    printf("Interactive Keyboard Input\n");
    printf("Type something and press Enter. Type 'exit' to quit.\n");
    printf("shell> ");
    fflush(stdout);

    while (1) {
        ch = getchar();

        if (ch == '\n') {
            buffer[position] = '\0';

            printf("\n");

            if (strcmp(buffer, "exit") == 0) {
                break;
            }

            printf("Command entered: %s\n", buffer);

            position = 0;
            printf("shell> ");
            fflush(stdout);
        }
        else if (ch == 127 || ch == '\b') {
            if (position > 0) {
                position--;

                printf("\b \b");
                fflush(stdout);
            }
        }
        else if (position < BUFFER_SIZE - 1) {
            buffer[position++] = ch;
            putchar(ch);
            fflush(stdout);
        }
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &old_terminal);

    printf("\nShell terminated.\n");

    return 0;
}
