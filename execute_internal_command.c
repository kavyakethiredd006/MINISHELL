#include "main.h"

extern int status;
void execute_internal_commands(char *Input_string)
{
    if(strcmp(Input_string, "exit") == 0)
    {
        exit(0);
    }
    else if(strcmp(Input_string,"pwd") == 0)
    {
        char path[50];
        getcwd(path,sizeof(path));
        printf("%s\n",path);
    }
    else if(strcmp(Input_string, "cd") == 0)
    {
        if(strlen(Input_string) <= 3)
        {
            chdir(getenv("HOME"));
        }
        else
        {
            chdir(Input_string + 3);  
        }
    }

    else if(strcmp(Input_string,"echo $$") == 0)
    {
        echo(Input_string);
    }
    else if(strcmp(Input_string, "jobs") == 0)
		{
			print_list(head);
		}
		else if(strcmp(Input_string, "fg") == 0)
		{
			if(head != NULL)
			{
				 kill(head->child_pid, SIGCONT);
               int pid= waitpid(head->child_pid, &status, WUNTRACED);
               if(pid == head->child_pid)
                {
                  delete_first(&head);
                }
			}
		}
		 else if(strcmp(Input_string, "bg") == 0)
        {
            if(head != NULL)
            {
                kill(head->child_pid, SIGCONT);
            }
        }
}