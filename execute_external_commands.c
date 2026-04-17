#include "main.h"

extern char Input_string[100];

void execute_external_commands(char *Input_string)
{

    char *cmd_with_option[strlen(Input_string) + 1];
    for(int n = 0 ; n < strlen(Input_string) + 1 ; n++)
        cmd_with_option[n] = NULL;

    int i = 0,k = 0,count = 0,count_p = 0;

    char buffer[100];
    while(Input_string[i] != '\0')
    {
	    if(Input_string[i] == ' ')
	    {
	        buffer[k] = '\0';
	        cmd_with_option[count] = calloc(strlen(buffer) + 1,sizeof(char));
	        strcpy(cmd_with_option[count],buffer);
            memset(buffer, 0, sizeof(buffer));
	        k = 0;
            i++;
	        count++;
	    }
	    else
	    {
	        buffer[k++] = Input_string[i];
            i++;
	    }
    }

    if(k > 0)
    {
        buffer[k] = '\0';
        //cmd_with_option[count] = calloc(strlen(buffer) + 1, sizeof(char));
        cmd_with_option[count] = strdup(buffer);
        count++;
    }

    cmd_with_option[count] = NULL;

    for(int a = 0 ; Input_string[a] ; a++ )
    {
        if(Input_string[a] == '|')
        count_p++;
    }

    if(count_p > 0)
    {
        n_pipe(cmd_with_option, count);
    }
    else
    {
        execvp(cmd_with_option[0],cmd_with_option); 
    }
}


