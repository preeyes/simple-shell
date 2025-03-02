#include <stdio.h>
#include "parser.h"
#include "excutor.h"

int main(){

// needs loop to continue asking for command untill user exits the shell
while (1){

    char input[1024];
    char* args[10];
    get_input(input);
    parse_input(input, args);
    
    execute_external(args);

}
    return 0;
}