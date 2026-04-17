#include "main.h"

extern int status;
void echo(char *Input_string)
{
    int ret;
    ret = strcmp(Input_string,"echo $$");
    if(ret == 0)
    {
        printf("%d\n",getpid());
    }
    ret = strcmp(Input_string,"echo $?");
    if(ret == 0)
    {
        if(WIFEXITED(status))
        {
            printf("%d\n",WEXITSTATUS(status));
        }
    }
    ret = strcmp(Input_string,"echo $SHELL");
    if(ret == 0)
    {
        char *shell = getenv("SHELL");
          if(shell)
            printf("%s\n", shell);
    }
}