#include "builtins.h"

typedef struct{
    char *name;
    void (*func)(char *arg[10]);
} BuiltinCommands;

BuiltinCommands builtins[] = {
    {"cd", builtin_cd},
    {"exit", buildin_exit}
};

int num_builtins = sizeof(builtins) / sizeof(builtins[0]);

int is_builtin(char* args[10]){

    char* builtin[] = {"cd", "exit"};
    int num_builtin = sizeof(builtin) / sizeof(builtin[0]);

    for(int i = 0; i< num_builtin;i++){
        if(strcmp(args[0], builtin[i]) == 0){
            return 1;
        }
    }
    return 0;
}

void execute_builtin(char* args[10]){
    
    for(int i = 0; i< num_builtins; i++){
        if(strcmp(args[0], builtins[i].name) == 0){
            return builtins[i].func(args);
        }
    }
}


void buildin_exit(){
    exit(1);
}

void builtin_cd(char* args[10]){
    chdir(args[1]);
}
