#include "monty.h"
/**
* mul_top_node - multiply  second top node by first node
* @stack: doublylist
* @li: line number
* Return: void
*/
void mul_top_node(stack_t **stack, unsigned int li)
{
stack_t *temp = *stack;
int res = 0;
if (!temp  || !temp->next)
{
	short_err(li, "mul");
}
else
{
	res = temp->next->n * temp->n;
	temp->next->n = res;
	temp->next->prev = NULL;
	*stack = temp->next;
	free(temp);
}
}
/**
* mod_top_node - remainder  second top node by first top node
* @stack: doublylist
* @li: line number
* Return: void
*/
void mod_top_node(stack_t **stack, unsigned int li)
{
stack_t *temp = *stack;
int res = 0;
if (!temp  || !temp->next)
{
	short_err(li, "mod");
}
else
{
	if (temp->n == 0)
	{
		divbyzero_err(li);
	}
	res = temp->next->n % temp->n;
	temp->next->n = res;
	temp->next->prev = NULL;
	*stack = temp->next;
	free(temp);
}
}

/**
* pchar_top_node - print the char of top stack
* @stack: doublylist
* @li: line number
* Return: void
*/
void pchar_top_node(stack_t **stack, unsigned int li)
{
stack_t *temp = *stack;
char ascii;

if (!temp)
{
	empty_err(li, "pchar", 11);
}
else
{
	if (temp->n < 0 || temp->n > 127)
	{
		val_err(li, "pchar");
	}
	ascii = (char)temp->n;
	fprintf(stdout, "%c\n", ascii);
}
}

