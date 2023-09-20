#include "monty.h"
#include "errors.h"
char *stack_data;
/**
* add_nodeint_end  - push data to stack
* @stack: doublylist stack
* @line_number: number of line the instruction exist
* Return: void
*/
void add_nodeint_end(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;
	stack_t *temp = *stack;
	stack_t *prev = NULL;
	int data = 0;

	new_node = malloc(sizeof(stack_t));
	/*malloc failed*/
if (new_node == NULL)
	malloc_err();
data = atoi(stack_data);

if (*stack_data != '0' && data == 0)
{
	push_err(line_number);
	free(new_node);
}
new_node->n = data;
if (stack == NULL)
{
new_node->prev = NULL;
*stack = new_node;
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
* handle_opcode  - controller to excute function pointers
* @stack: doublylist stack
* @list_tok: list contains tokens of instruction
* @line_number: number of line the instruction exist
* Return: void
*/
void handle_opcode(stack_t **stack, List *list_tok, unsigned int line_number)
{
	char *opcode = NULL;
	int len_ops = 0;
	int i = 0;

	instruction_t ops[] = {
		{"push", add_nodeint_end},
		{"pall", print_stack}
	};
len_ops = sizeof(ops) / sizeof(ops[0]);
if (list_tok != NULL)
	opcode = list_tok->arg;
if (list_tok->next != NULL)
	stack_data  = list_tok->next->arg;
for (i = 0; i < len_ops; i++)
{
	if (strcmp(opcode, ops[i].opcode) == 0)
		ops[i].f(stack, line_number);
}
}
