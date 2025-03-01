#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(){

// needs loop to continue asking for command untill user exits the shell
while (1){
// needs input parser 

    char input[1024];
    
    printf("$  ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    if(strcmp(input, "exit") == 0){
        exit(1);
    }

    char *args[10];
    int i = 0;

    char *token = strtok(input, " ");
    while (token != NULL && i< 9){
        args[i++] = token;
        token = strtok (NULL, " ");
    }

    args[i] = NULL;

    // you gotta write a fucntion that breaks the input into 
    // commands and arguments and store them in
    // char const & argv[]

    pid_t p = fork();
    if(p<0){
        perror("fork failed");
        exit(1);
    }

    else if(p == 0){
        // needs error handling in execvp

        execvp(args[0], args);

    }

    else{
        waitpid(p, NULL, 0);
    }
}
    return 0;
}