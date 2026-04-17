 #include "main.h"

extern Slist *head;
extern char Input_string[100];
extern int pid;
void signal_handler(int signum)
{
    if(signum == SIGINT)
    {
        printf("\n%s ", prompt_name);
        fflush(stdout);
    }

    if(signum == SIGTSTP)
    {
        if(pid > 0)
        {
            
            insert_first(&head);
          printf(ANSI_COLOR_YELLOW "\n[%d] Stopped %s\n" ANSI_COLOR_RESET, pid, Input_string);
            
           
        }
        else
        {
           printf("\n%s ", prompt_name);
           fflush(stdout);
        }
    }

    if(signum == SIGCHLD)
    {
        int status;
        pid_t child = waitpid(-1, &status, WNOHANG);

        if(child > 0)
        {
            delete_first(&head);
        }
    }
}