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
