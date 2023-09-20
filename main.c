#include "monty.h"
#include <stdio.h>
#include "strings.h"
/**
* main - entry point to the execution of program
* @ac: arguments count
* @argv: arguments vector
* Return: (0 or exit error code)
*/

int main(int ac, char *argv[])
{
/*declare variables */
FILE *stream;
int numline = 0;
char line_buffer[MAX_LINE_LENGTH];
char *sep = " \n\r\t\a", *token = NULL;
stack_t *stack = NULL;
List *list_tok = NULL;
if (ac != 2)
{
	/*print error and exit*/
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
stream = fopen(argv[1], "r");
if (stream == NULL)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
	exit(EXIT_FAILURE);
}

while (fgets(line_buffer, sizeof(line_buffer), stream))
{
	numline++;
	token = strtok(line_buffer, sep);
	while (token != NULL)
	{
		if (!is_empty(token))
			add_token_to_list(&list_tok, token);
		token = strtok(NULL, sep);
	}
	handle_opcode(&stack, list_tok, numline);
	cleanupList(&list_tok);
}
return (0);
}

