#include "my_shell.h"
/**
 * main - build a shell
 * @argc: number of arguments
 * @argv: pointer to the address of arguments
 * @envs: environment
 * Return: int
 */
int main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)), char **envs)
{
	char *line = NULL;
	int count = 0;
	char *CommandPath = NULL, *envPath;

	envPath = getenv("PATH");
	signal(SIGINT, new_signal_handler); /*SIGINT = Interrupt the process*/

	while (true)
	{
		line = NULL;
		CommandPath = NULL;
		count++;

		if (isatty(STDIN_FILENO) == 1)
		{
			if (write(STDOUT_FILENO, "$ ", 2) == EOF) /* print the prompt*/
				exit(EXIT_FAILURE);
		}
		_getline(&line); /* Line provided by user*/
		sll = parse_sll(line);
		free(line);

		if (built_in(sll_t, envs))
			continue;

		CommandPath = get_path_from_Command(sll, envPath);
		if (!CommandPath)
		{
			printf("%s: Command not found\n", sll->Command);
			free(CommandPath), free_all(sll);
			continue;
		}
		nobuilt_in(sll, CommandPath);
		free(CommandPath), free_all(sll);
	}
	return (EXIT_SUCCESS);
}
