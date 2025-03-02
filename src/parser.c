#include "parser.h"


void get_input(char input[1024]){
    printf("$  ");
    fgets(input, 1024, stdin);
    input[strcspn(input, "\n")] = 0;

}

void parse_input(char* input, char* args[10]){

    int i = 0;

    char *token = strtok(input, " ");
    while (token != NULL && i< 9){
        args[i++] = token;
        token = strtok (NULL, " ");
    }

    args[i] = NULL;

}