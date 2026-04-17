#include "main.h"

char *get_command(char *Input_string)
{
    char *command = calloc(strlen(Input_string) + 1 , sizeof(char));
    int i ;
    for( i = 0 ; Input_string[i] != '\0' && Input_string[i] != ' ' ; i++)
    {
	    command[i] = Input_string[i];
    }
    command[i] = '\0';

    return command;
}

