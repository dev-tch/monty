#include <stdio.h>
#include <stdlib.h>
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
