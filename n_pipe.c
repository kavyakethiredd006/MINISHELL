#include "main.h"

void n_pipe(char **cmd_with_options, int pipe_count)
{
    int cmd_pos[pipe_count + 1];
    int cmd_count = 0;

    cmd_pos[cmd_count++] = 0;
    for (int i = 1; cmd_with_options[i] != NULL; i++) 
    {
        if (strcmp(cmd_with_options[i], "|") == 0) 
        {
            cmd_pos[cmd_count++] = i + 1;
            cmd_with_options[i] = NULL;
        }
    }

    int prev_fd = -1;

    for (int i=0; i<cmd_count; i++)
    {
        int fd[2];
        if (i < cmd_count - 1) {
           if (pipe(fd) == -1) {
               perror("pipe");
               return;
            }
        }

        int pid = fork();
        if (pid == 0)
        {
           // Child
           if (prev_fd != -1) {
              dup2(prev_fd, 0);
              close(prev_fd);
            }

            if (i < cmd_count - 1) {
               dup2(fd[1], 1);
               close(fd[0]); // close read end
               close(fd[1]);
            }

            int ret = execvp(cmd_with_options[cmd_pos[i]], &cmd_with_options[cmd_pos[i]]);

            if (ret == -1)
            {
                printf("Error: Command not found!\n");
                return;
            }
        }
        else
        {
            // Parent
            int new_stdin = dup(0);
            int status;
            wait(&status);

            if (prev_fd != -1) 
               close(prev_fd);

            if (i < cmd_count - 1) {
               close(fd[1]);
               prev_fd = fd[0]; // save read end for next command
            }
        }
    }
}