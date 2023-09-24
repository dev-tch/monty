#include <ctype.h>
#include <stdlib.h>
#include <string.h>
/**
* is_space - check character space
* @c: a character
* Return: (1 or 0)
*/

int is_space(char c)
{
return (c == ' ' || c == '\t' || c == '\r');
}
/**
* is_empty - check empty string
* @str: a string
* Return: (1 or 0)
*/

int is_empty(char  *str)
{
	if (str == NULL)
	{
	return (1);
	}

	while (*str != '\0')
	{
		if (!is_space(*str))
		return (0);
		str++;
	}

	return (1);
}
/**
*_strdup - new pointer to copied string
*@str: string
*Return: a pointer to string
*/
char *_strdup(char *str)
{
	char *cpy = NULL;
	char *bkp = str;
	int len = 0, i;

	if (str == NULL)
		return (NULL);
	/*get the length*/
	while (*str)
	{
		len++;
		str++;
	}
	/* memory allocation*/
	cpy = (char *) malloc((len + 1) * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	for (i = 0 ; i < len ; i++)
	{
		cpy[i] = bkp[i];
	}
	/*add character terminating to string*/
	cpy[i] = '\0';
	return (cpy);
}

/**
 * _isdigit - checks for a digit from 0 to 9
 * @str: the integer to be checked
 *
 * Return: 1 if is digit, 0 otherwise
 */
int _isdigit(char *str)
{
	int digit = 1;
	int i = 0;

	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (i == 0 && (str[0] == '+' || str[0] == '-') && str[1] != '\0')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
		{
			digit = 0;
			break;
		}
		i++;
	}
	return (digit);
}

/**
* _strtok_r - split with different delimiters in two while loops
* @line: data to split
* @sep: delimiters
* @ptr: pointer to save the position of split
* Return: token after each split
*/
char *_strtok_r(char *line, const char *sep, char **ptr)
{
	char *token;

	if (line != NULL)
	{
		*ptr = line;
	}

	if (*ptr == NULL || **ptr == '\0')
	{
		return (NULL);
	}

	while (**ptr != '\0' && strchr(sep, **ptr) != NULL)
	{
		(*ptr)++;
	}
	if (**ptr == '\0')
	{
		return (NULL);
	}
	token = *ptr;
	while (**ptr != '\0' && strchr(sep, **ptr) == NULL)
	{
		(*ptr)++;
	}

	if (**ptr != '\0')
	{
		**ptr = '\0';
		(*ptr)++;
	}
	return (token);
}
