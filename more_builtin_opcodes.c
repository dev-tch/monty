#include "monty.h"
/**
* swap_top_node - swap the two top nodes
* @stack: doublylist
* @li: line number
* Return: void
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
* Return: void
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
/**
* do_nothing - nothing to make
* @stack: doublylist
* @li: line number
* Return: void
*/
void do_nothing(stack_t **stack, unsigned int li)
{
	(void)stack;
	(void)li;
}
/**
* sub_top_node - sub first node and second node
* @stack: doublylist
* @li: line number
* Return: void
*/
void sub_top_node(stack_t **stack, unsigned int li)
{
stack_t *temp = *stack;
int res = 0;
if (!temp  || !temp->next)
{
	short_err(li, "sub");
}
else
{
	res = temp->next->n - temp->n;
	temp->next->n = res;
	temp->next->prev = NULL;
	*stack = temp->next;
	free(temp);
}
}

/**
* div_top_node - divide second top node by first node
* @stack: doublylist
* @li: line number
* Return: void
*/
void div_top_node(stack_t **stack, unsigned int li)
{
stack_t *temp = *stack;
int res = 0;
if (!temp  || !temp->next)
{
	short_err(li, "div");
}
else
{
	if (temp->n == 0)
	{
		divbyzero_err(li);
	}
	res = temp->next->n / temp->n;
	temp->next->n = res;
	temp->next->prev = NULL;
	*stack = temp->next;
	free(temp);
}
}
