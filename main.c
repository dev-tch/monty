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
if (ac != 2)
{
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
	/*treat comments*/
	if (data.line_buffer[0] == '#')
	{
		memset(data.line_buffer, 0, MAX_LINE_LENGTH);
		continue;
	}
	split_data(data.line_buffer, numline);
	memset(data.line_buffer, 0, MAX_LINE_LENGTH);
}
free_dlistint(data.stack);
fclose(data.fp); /*Close the stream file*/
return (0);
}
