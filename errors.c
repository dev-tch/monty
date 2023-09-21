#include "monty.h"
/**
* malloc_err - show and exit if error malloc found
* Return: void
*/
void malloc_err(void)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
/**
* push_err - show and exit if error int conversion found
* @line_number: number of line the instruction exist
* Return: void
*/
void push_err(int line_number)
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}

/**
* push_err404 - show and exit if error instruction not  found
* @line_number: number of line the instruction exist
* Return: void
*/
void push_err404(int line_number)
{
	char *pb = NULL;

	if (list_tok)
	{
		pb = list_tok->arg;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, pb);
	exit(EXIT_FAILURE);
}

/**
* pint_err - error for invalid pint opcode
* @line_number: number of line the instruction exist
* Return: void
*/
void pint_err(int line_number)
{
	fprintf(stderr, "L<%d>: can't pint, stack empty\n", line_number);
	exit(EXIT_FAILURE);
}

