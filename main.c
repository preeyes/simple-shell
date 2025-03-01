#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(){

// needs loop to continue asking for command untill user exits the shell
    
// needs input parser 

    char input[20];

    printf("$  ");
    scanf("%s", input);
    printf("You typed: %s/n", input);

    // you gotta write a fucntion that breaks the input into 
    // commands and arguments and store them in
    // char const & argv[]

    pid_t p = fork();
    if(p<0){
        perror("fork failed");
        exit(1);
    }

    else if(p == 0){
        char *args[] = {"ls", "-l", NULL};

        // needs error handling in execvp

        execvp("ls", args);

    }

    else{

        // needs to use waitpid for parents to wait // i mean things to do still aint figured out
        // waitpid(pid, NULL, 0);
        wait(NULL);
    }

    return 0;
}