#include "monty.h"
/**
* divbyzero_err - error for when divide by zero
* @line_number: number of line the instruction exist
* Return: void
*/
void divbyzero_err(int line_number)
{
	fprintf(stderr, "L%d: division by zero\n", line_number);
	free_data();
	exit(EXIT_FAILURE);
}

/**
* val_err - error if value out of range
* @line_number: number of line the instruction exist
* @msg: opcode
* Return: void
*/
void val_err(int line_number, char *msg)
{
	fprintf(stderr, "L%d: can't %s, value out of range\n", line_number, msg);
	free_data();
	exit(EXIT_FAILURE);
}

