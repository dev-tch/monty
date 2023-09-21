#include "monty.h"
#include "errors.h"
/**
* swap_top_node - swap the two top nodes
* @stak: doublylist
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
