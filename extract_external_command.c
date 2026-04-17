#include "main.h"

void extract_external_commands(char **external_command)
{
    int fd = open("external_command.txt", O_RDONLY);
    if(fd == -1)
    {
        printf("file not opened\n");
        return;
    }

    //printf("external_command.txt is opened successfully\n");

    int i = 0;
    char ch;
    char cmd[100];
    int count = 0;

    while(read(fd, &ch, 1) > 0)
    {
        if(ch == '\n' || ch == '\r')
        {
            cmd[i] = '\0';
            if(i > 0)
            {
                external_command[count++] = strdup(cmd);
            }
          
            
            i = 0;
        }
        else
        {
            cmd[i++] = ch;
        }
    }

    external_command[count] = NULL;

    // printf("Total commands = %d\n", count);

    // for(int i = 0; external_command[i] != NULL; i++)
    // {
    //     printf("%s\n", external_command[i]);
    //      printf("%d\n", strlen(external_command[i]));
    //      sleep(2);
    // }

    close(fd);
}




