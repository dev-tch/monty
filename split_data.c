#include "monty.h"
/**
* split_data - split line to command , arg
* @line: line contents
* @numline: number of line
* Return: void
*/

void split_data(char *line, int numline)
{
	const char outer_delimiters[] = ";";
	const char inner_delimiters[] = " \n\r\t\a";
	char *outer_saveptr = NULL;
	char *inner_saveptr = NULL;
	char *token;
	char *inner_token;
	char *opcode, *arg;

	token = _strtok_r(line, outer_delimiters, &outer_saveptr);

	while (token != NULL)
	{
		inner_token = _strtok_r(token, inner_delimiters, &inner_saveptr);
		opcode = inner_token;

		if (inner_token != NULL)
		{
			inner_token = _strtok_r(NULL, inner_delimiters, &inner_saveptr);
			arg = inner_token;
		}

		if (!is_empty(opcode))
		{
			add_token_to_list(&(data.list_tok), opcode);
			if (!is_empty(arg))
			{
				add_token_to_list(&(data.list_tok), arg);
			}
			if (data.list_tok)
			{
				handle_opcode(&(data.stack),  numline);
				cleanupList(&(data.list_tok));
			}
		}
		token = _strtok_r(NULL, outer_delimiters, &outer_saveptr);
	}
}
