#include <stdlib.h>
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
