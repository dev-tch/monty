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
