#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define CMD_LIST_SIZE 3
#define PATH_LIST_SIZE 1

char *cmd_list[] = {"echo", "exit", "type"};
char *path_list[] = {"/usr/bin/"};

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
        } else if (strcmp(token, "type") == 0) {

            token = strtok(NULL, " ");
            if (token == NULL) {
                printf("Invalid usage of type: type <command>\n");
            } else {

                int index = -1;
                for (int i = 0; i < CMD_LIST_SIZE; i++) {
                    if (strcmp(token, cmd_list[i]) == 0) {
                        index = i;
                    }
                }

                //for built-in
                if (index > 0) {
                    char *cmd = cmd_list[index];
                    printf("%s is a shell builtin\n", cmd);
                } else {


                    printf("%s: not found\n", token);
                }

            }

        } else
            printf("%s command not found\n", input);
    }
}
