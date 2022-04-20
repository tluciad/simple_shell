#include "my_shell.h"
/**
 * GETline - function to line the input provided by the user
 * @line: parameter to be read
 */
void GETline(char **line)

{
	size_t len = 0;
	ssize_t nread = 0;

	nread = getline(line, &len, stdin);
	if (nread == EOF)
	{
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "\n", 1);
		if (*line)
			free(*line);

		exit(EXIT_SUCCESS);
	}
}

/**
 * R_spaces - function that removes spaces in the input string
 * @sll: shell structure
 */
void R_spaces(sll_t *sll)
{
	int i = 0, j = 0;

	while (sll->Command[i])
	{
		if (sll->Command[i] != ' ')
			sll->Command[j++] = sll->Command[i];
		i++;
	}
	sll->Command[j] = '\0';
}

/**
 * look_char - function to look up for an specific character
 * @sll: shell typedef structure
 * Return: int
 */
int look_char(sll_t *sll)
{
	int index = 0;
	int flag = 0;
	char cmp = '/';

	R_spaces(sll);

	while (sll->Command[index])
	{
		if (sll->Command[index] == cmp)
		{
			flag = 1;
			return (flag);
		}
		index++;
	}
	return (flag);
}
