#include "monty.h"
/**
* malloc_err - show and exit if error malloc found
* Return: void
*/
void malloc_err(void)
{
fprintf(stderr, "Error: malloc failed\n");
free_data();
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
free_data();
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

	if (data.list_tok)
	{
		pb = data.list_tok->arg;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, pb);
	free_data();
	exit(EXIT_FAILURE);
}

/**
* empty_err - error for empty stack
* @line_number: number of line the instruction exist
* @msg: opcode
* @code: error code
* Return: void
*/
void empty_err(int line_number, char *msg, int code)
{
	/*pop error :  code 10*/
	if (code == 10)
		fprintf(stderr, "L%d: can't %s an empty stack\n", line_number, msg);
	/*pint err: code 11*/
	else if (code == 11)
		fprintf(stderr, "L%d: can't %s, stack empty\n", line_number, msg);
	free_data();
	exit(EXIT_FAILURE);
}

/**
* short_err - error for less elmements in  stack
* @line_number: number of line the instruction exist
* @msg: opcode
* Return: void
*/
void short_err(int line_number, char *msg)
{
	fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, msg);
	free_data();
	exit(EXIT_FAILURE);
}

