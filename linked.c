 #include "main.h"

 extern int pid;
void insert_first(Slist ** head)
{
    Slist*new = malloc(sizeof(Slist));
    if(!new)
      return;

    new->child_pid = pid;
    strcpy(new->cmd_name, Input_string);

    new->link = *head;
    *head = new;

    return;
}
void delete_first(Slist ** head)
{
    if(*head == NULL)
        return; 

    Slist *temp = *head;
    *head = (*head)->link;
    free(temp);

    return;
}
void print_list(Slist *head)
{
    Slist *tem = head;
    int i = 1;
    while (tem != NULL)
{
     printf(ANSI_COLOR_CYAN "[%d] %d %s\n" ANSI_COLOR_RESET,i++, tem->child_pid, tem->cmd_name);
    tem = tem->link;
}
}
