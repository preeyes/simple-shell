#include "excutor.h"

void execute_external(char* args[10]){
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