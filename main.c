#include "main.h"

Slist *head = NULL;
char *external_command[154];
char Input_string[100];
char prompt_name[20] =  ANSI_COLOR_GREEN "minshell$" ANSI_COLOR_RESET;
int main()//min_shell file
{
    system("clear");
    extract_external_commands(external_command);
    scan_input(prompt_name, Input_string);
}
