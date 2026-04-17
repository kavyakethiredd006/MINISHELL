#include "main.h"

extern char *external_command[154];
int check_command_type(char *command)
{
   char *builtins[] = {"echo", "printf", "read", "cd", "pwd", "pushd", "popd", "dirs", "let", "eval",
       "set", "unset", "export", "declare", "typeset", "readonly", "getopts", "source",
       "exit", "exec", "shopt", "caller", "true", "type", "hash", "bind", "help","fg","bg","jobs", NULL};

    for(int i =0 ; builtins[i] != NULL ; i++)
    {
	    if (strcmp(command, builtins[i]) == 0)
	    
	    {
	        return BUILTIN;
	    }
    }

    for(int i = 0; external_command[i] != NULL; i++)
    {
        if(strcmp(command, external_command[i]) == 0 )
	    {
	        return EXTERNAL;
	    }
    }

    return NO_COMMAND;
}






