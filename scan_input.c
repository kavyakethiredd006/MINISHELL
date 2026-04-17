#include "main.h"

int status;
int pid ;
void scan_input(char *prompt_name, char *Input_string)
{
	signal(SIGINT,signal_handler);
	signal(SIGTSTP,signal_handler);

    while(1)
    {
	    char path[50];
	    getcwd(path,sizeof(path));
	   printf("%s ",prompt_name);
	   if(scanf("%[^\n]",Input_string) != 1)
	   {
		getchar();
		continue;

	   }
	   getchar();    

	   if(strncmp(Input_string, "PS1=", 4) == 0)
	   {
		if(Input_string[4] == ' ' || Input_string[4] == '\0')
		{
			printf("Invalied PS1 command\n");
			return ;
		}
		else
		{
			strcpy(prompt_name, Input_string + 4);

		}
		memset(Input_string, 0, sizeof(Input_string));
		continue;
		
	   }
	   char *command=get_command(Input_string);
	   int type = check_command_type(command);

	   if(type == EXTERNAL)
	   {
		pid=fork();
		if(pid == 0)
		{
			signal(SIGINT, SIG_DFL);
	        signal(SIGTSTP, SIG_DFL);
			execute_external_commands(Input_string);
		}
		else
		{
           waitpid(pid,&status,WUNTRACED);
		}
	   }
	   else if(type == BUILTIN)
	   {
		  execute_internal_commands(Input_string);
	   }
	   else
	   {
		printf(ANSI_COLOR_RED "command not found\n" ANSI_COLOR_RESET);
	   }

	}
}