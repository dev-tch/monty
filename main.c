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
char *sep = " \n\r\t\a", *token = NULL;
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
init(stream);
while (fgets(data.line_buffer, sizeof(data.line_buffer), stream))
{
	numline++;
	token = strtok(data.line_buffer, sep);
	while (token != NULL)
	{
		if (!is_empty(token))
			add_token_to_list(&(data.list_tok), token);
		token = strtok(NULL, sep);
	}

	if (data.list_tok && data.list_tok->arg)
	{
		handle_opcode(&(data.stack),  numline);
		cleanupList(&(data.list_tok));
	}
	/*clear the line*/
	memset(data.line_buffer, 0, MAX_LINE_LENGTH);
}
free_dlistint(data.stack);
fclose(data.fp); /*Close the stream file*/
return (0);
}
