#include "my_shell.h"
/**
 * free_all - Function to free all dynamic memory allocated
 * @cmd: pointer to Command element of structure
 */

void free_all(sll_t *cmd)
{
	int i = 0;

	if (cmd)
	{
		free(cmd->Command);
		cmd->Command = NULL;

		if (cmd->flags)
		{
			for (; i < cmd->num_flags; i++)
			{
				if (cmd->flags[i])
					free(cmd->flags[i]);
			}
			free(cmd->flags);
			cmd->flags = NULL;
		}
		free(cmd);
		cmd = NULL;
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
 * new_cmd - to determinate the Command in the input
 * @num_flags : number of flags in the string
 * Return: cmd
 */
sll_t *new_cmd(int num_flags)
{
	sll_t *cmd = (sll_t *)malloc(sizeof(sll_t));

	if (!cmd)
		return (NULL);

	cmd->num_flags = num_flags;
	cmd->Command = NULL;
	cmd->flags = NULL;

	cmd->flags = (char **)malloc(sizeof(char *) * num_flags);
	if (cmd->flags == NULL)
	{
		free_all(cmd);
		return (NULL);
	}
	return (cmd);
}
/**
 * parse_cmd - to manage the string input
 * @input: what the user write in the input
 * Return: Command of the string
 */
sll_t *parse_cmd(char *input)
{
	int i = 0, flags_count = 0;
	sll_t *cmd = NULL;
	char *token = NULL;

	/** Remove the last character '\n' for '\0' */
	if (input[strlen(input) - 1] == '\n') /*Remove the "\n" of the end*/
		input[strlen(input) - 1] = '\0';  /*from the variable - (line)*/

	flags_count = count_flags_by_space(input); /*Return the count of the flags*/

	cmd = new_cmd(flags_count);
	if (!cmd)
		return (NULL);

	if (cmd->num_flags == 0)
	{
		cmd->Command = _strdup(input);
		return (cmd);
	}

	token = strtok(input, " "); /*Input: ls -l -a -b*/
	while (token != NULL)		/*Command = [ls] [-l] [-a] [-b]*/
	{
		if (cmd->Command == NULL)
			cmd->Command = _strdup(token);

		else
			cmd->flags[i] = _strdup(token), i++;

		token = strtok(NULL, " ");
	}
	return (cmd);
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
