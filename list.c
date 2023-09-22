#include "monty.h"
/**
* add_token_to_list - add node at the list
* @head: pointer of pointers contains the pointer to each node
*@str: string to be added at the new node
*Return: the adress of new node
*/

list_t *add_token_to_list(list_t **head,  char *str)
{
	list_t  *new_node, *temp;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);
	/*initilize next node */
	new_node->next = NULL; /*fix the problem of double free dtected*/
	if (str != NULL)
	{
		new_node->arg =  _strdup(str);
		if (new_node->arg == NULL)
		{
			free(new_node);
			return (NULL);
		}
		new_node->len = strlen(new_node->arg);
	} /*if str!=NULL*/

	else
	{
		new_node->arg  = NULL;
		new_node->len  = 0;
	}
	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		temp = *head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
	temp->next = new_node;
	}
	return (new_node);
}


/**
* free_list - empty linked list
* @head: pointer of pointers to nodes
*Return: void
*/
void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->arg);
		temp->arg = NULL;
		free(temp);
	}
}
/**
* cleanupList - clean ressources used
* @head: list of nodes
* Return: void
*/
void cleanupList(list_t **head)
{
	/* condition to ovoid error double free detected*/
	if (head == NULL || *head == NULL)
		return;

	free_list(*head);
	 *head = NULL;
}
