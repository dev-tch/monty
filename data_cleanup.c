#include "monty.h"

/**
* free_dlistint - free list
* @head: list
* Return: void
**/
void free_dlistint(stack_t *head)
{
stack_t *temp = NULL;
if (head == NULL)
return;
while (head != NULL)
{
temp = head->next;
free(head);
head = temp;
}
}

/**
* free_data - clean working data
* Return: void
*/
void free_data(void)
{
	memset(data.line_buffer, 0, MAX_LINE_LENGTH);
	cleanupList(&(data.list_tok));
	free_dlistint(data.stack);
	fclose(data.fp);
}
