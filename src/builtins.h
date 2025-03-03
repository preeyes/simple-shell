#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int is_builtin(char* args[10]);
void execute_builtin(char* args[10]);

void builtin_cd(char* args[10]);
void buildin_exit();

