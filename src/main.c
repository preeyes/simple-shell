
#include "parser.h"
#include "excutor.h"
#include "builtins.h"

int main(){

// needs loop to continue asking for command untill user exits the shell
while (1){

    char input[1024];
    char* args[10];
    get_input(input);
    parse_input(input, args);

    int builtin =  is_builtin(args);

    if(builtin){
        execute_builtin(args);
    }
    else{
        execute_external(args);
    }

}
    return 0;
}