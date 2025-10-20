#include <stdio.h>
#include <string.h>

void myShell();

int main() {
    setbuf(stdout, NULL);
    myShell();

    return 0;
}

void myShell() {
    int size = 100;
    while (1) {
        printf("$ ");

        char input[size];
        char *str = fgets(input, size, stdin);

        if (str == NULL) {
            break;
        }

        char *p = strchr(input, '\n');
        *p = '\0';

        if (strncmp(str, "exit 0", 6) == 0)
            break;
        char *token = strtok(str, " ");

        if (strcmp(token, "echo") == 0) {

            token = strtok(NULL, " ");
            if (token == NULL) {
                printf("Invalid usage of echo: echo <text>\n");
            }

            while (token != NULL) {
                printf("%s", token);
                token = strtok(NULL, " ");
                if (token != NULL) printf(" ");
            }
            printf("\n");
        } else
            printf("%s command not found\n", input);
    }
}
