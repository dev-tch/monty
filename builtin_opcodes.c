#include "monty.h"
/**
* add_nodeint_end  - push data to stack
* @stack: doublylist stack
* @line_number: number of line the instruction exist
* Return: void
*/
void add_nodeint_end(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL, *temp = *stack, *prev = NULL;
	int conv = 0, flag = 1;

	new_node = malloc(sizeof(stack_t));
	/*malloc failed*/
	if (new_node == NULL)
		malloc_err();
	if (data.list_tok  && (data.list_tok)->next)
	{

		flag = strcmp((data.list_tok)->next->arg, "0");
		conv = atoi((data.list_tok)->next->arg);
	}
	if (flag  && conv == 0)
	{
		free(new_node);
		push_err(line_number);
	}
	new_node->n = conv;
	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->prev = NULL;
		new_node->next = NULL;
	}
	else
	{
		*stack = new_node;
		new_node->prev = NULL;
		new_node->next = temp;
		prev = new_node;
		while (temp != NULL)
		{
			temp->prev = prev;
			prev = temp;
			temp = temp->next;
		}
	}
}
/**
* print_stack  - display elmements of stack in stdout
* @stack: doublylist stack
* @li: number of line the instruction exist
* Return: void
*/
void print_stack(stack_t **stack, unsigned int li __attribute__((unused)))
{
stack_t *temp = *stack;
while (temp != NULL)
{
	fprintf(stdout, "%d\n", temp->n);
	temp = temp->next;
}
}
/**
* print_top_node  - print top node
* @stack: doublylist stack
* @li: number of line the instruction exist
* Return: void
*/
void print_top_node(stack_t **stack, unsigned int li)
{
stack_t *temp = *stack;

if (!temp)
{
	empty_err(li, "pint");
}
else
{
	fprintf(stderr, "%d\n", temp->n);
}

}

/**
* remove_top_node  - delete top node
* @stack: doublylist stack
* @li: number of line the instruction exist
* Return: void
*/
void remove_top_node(stack_t **stack, unsigned int li)
{
stack_t *temp = *stack;

if (!temp)
{
	empty_err(li, "pop");
}
else
{
	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
		return;
	}
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

}
/**
* handle_opcode  - controller to excute function pointers
* @stack: doublylist stack
* @line_number: number of line the instruction exist
* Return: void
*/
void handle_opcode(stack_t **stack, unsigned int line_number)
{
	int len_ops = 0;
	int i = 0, valid = 0;
	instruction_t ops[] = {
		{"push", add_nodeint_end},
		{"pall", print_stack},
		{"pint", print_top_node},
		{"pop", remove_top_node},
		{"swap", swap_top_node},
		{"add", add_sum_top},
		{"nop", do_nothing}
	};
len_ops = sizeof(ops) / sizeof(ops[0]);
for (i = 0; i < len_ops; i++)
{
	if (data.list_tok && strcmp(data.list_tok->arg, ops[i].opcode) == 0)
	{
		ops[i].f(stack, line_number);
		valid =  1;
		break;
	}
}
	if (!valid)
		push_err404(line_number);
}
