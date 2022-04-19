#include "my_shell.h"
/**
 * free_all - Function to free all dynamic memory allocated
 * @sll: pointer to Command element of structure
 */

void free_all(sll_t *sll)
{
	int i = 0;

	if (sll)
	{
		free(sll->Command);
		sll->Command = NULL;

		if (sll->flags)
		{
			for (; i < sll->num_flags; i++)
			{
				if (sll->flags[i])
					free(sll->flags[i]);
			}
			free(sll->flags);
			sll->flags = NULL;
		}
		free(sll);
		sll = NULL;
	}
}
/**
 * count_flags_by_space -  to determinate the number of arguments
 * after Command
 * @input: the user input
 * Return: the count of flags
 */
int count_flags_by_space(char *input)
{
	int count = 0;

	char *dup = _strdup(input);	/*Duplicate the "input" variable*/
	char *token = strtok(dup, " "); /*the function strtok() modified*/

	while (token != NULL)
		count++, token = strtok(NULL, " "); /*Make a count of all input*/

	count = count >= 1 ? (count - 1) : 0; /*condition ? case true : case false;*/

	return (count);
}
/**
 * new_sll - to determinate the Command in the input
 * @num_flags : number of flags in the string
 * Return: sll
 */
sll_t *new_sll(int num_flags)
{
	sll_t *sll = (sll_t *)malloc(sizeof(sll_t));

	if (!sll)
		return (NULL);

	sll->num_flags = num_flags;
	sll->Command = NULL;
	sll->flags = NULL;

	sll->flags = (char **)malloc(sizeof(char *) * num_flags);
	if (sll->flags == NULL)
	{
		free_all(sll);
		return (NULL);
	}
	return (sll);
}
/**
 * parse_sll - to manage the string input
 * @input: what the user write in the input
 * Return: Command of the string
 */
sll_t *parse_sll(char *input)
{
	int i = 0, flags_count = 0;
	sll_t *sll = NULL;
	char *token = NULL;

	/** Remove the last character '\n' for '\0' */
	if (input[strlen(input) - 1] == '\n') /*Remove the "\n" of the end*/
		input[strlen(input) - 1] = '\0';  /*from the variable - (line)*/

	flags_count = count_flags_by_space(input); /*Return the count of the flags*/

	sll = new_sll(flags_count);
	if (!sll)
		return (NULL);

	if (sll->num_flags == 0)
	{
		sll->Command = _strdup(input);
		return (sll);
	}

	token = strtok(input, " "); /*Input: ls -l -a -b*/
	while (token != NULL)		/*Command = [ls] [-l] [-a] [-b]*/
	{
		if (sll->Command == NULL)
			sll->Command = _strdup(token);

		else
			sll->flags[i] = _strdup(token), i++;

		token = strtok(NULL, " ");
	}
	return (sll);
}
/**
 * new_signal_handler - new atribute to signal
 * @attribute: parameter
 * @pid: process id
 */
void new_signal_handler(int pid __attribute__((unused)))
{
	if (write(STDOUT_FILENO, "\n$ ", 3) == EOF) /*prompconte signo*/
		exit(EXIT_FAILURE);
}
