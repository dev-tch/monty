#include "monty.h"
#include "errors.h"
/**
* swap_top_node - swap the two top nodes
* @stack: doublylist
* @li: line number
*/
void swap_top_node(stack_t **stack, unsigned int li)
{
stack_t *temp = *stack;
stack_t *save = NULL;
if (!temp  || !temp->next)
{
	short_err(li, "swap");
}
else
{
	save = temp->next;
	*stack = save;
	temp->prev = save;
	temp->next  = save->next;
	if (save->next)
		save->next->prev = temp;
	save->next = save->prev;
	save->prev = NULL;
}

}

/**
* add_sum_top - sum in second top + remove first top
* @stack: doublylist
* @li: line number
*/
void add_sum_top(stack_t **stack, unsigned int li)
{
stack_t *temp = *stack;
int sum = 0;
if (!temp  || !temp->next)
{
	short_err(li, "add");
}
else
{
	sum = temp->n + temp->next->n;
	temp->next->n = sum;
	temp->next->prev = NULL;
	*stack = temp->next;
	free(temp);
}

}
