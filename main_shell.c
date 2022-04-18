#include "my_shell.h"
/**
 * main - build a shell 
 * @argc: number of arguments
 * @argv: pointer to the address of arguments
 * @envs: environment 
 * Return: int 
 */
int main(int argc, char *argv[], char **envs)
{
	size_t len = 0;
	ssize_t nread = 0;
	char *line = NULL;
	int count = 0;
	struct stat statistics;
	char *commandPath = NULL, *envPath;

	envPath = getenv("PATH");

	signal(SIGINT, new_signal_handler);/*SIGINT = Interrupt the process*/

	while (true)
	{
		line = NULL;
		commandPath = NULL;
		count++;

		if (isatty(STDIN_FILENO) == 1)
		{
			if (write(STDOUT_FILENO, "$ ", 2) == EOF)/* print the prompt*/
				exit(EXIT_FAILURE);
		}
		if ((nread = getline(&line, &len, stdin)) == EOF) /* Line provided by user*/
		{
			if (isatty(STDIN_FILENO) != 0)	   // evalue the file descriptor standard input
				write(STDOUT_FILENO, "\n", 1); // to write in standard output

			exit(EXIT_FAILURE);
		}
		sll_t *cmd = parse_cmd(line);//Parse - Proccess a string and
		free(line);                  // Manipulate line(read buffer)
		printf("command: |%s|\n", cmd->command);
		/* ----------------------------------- builtin-functions----------------------*/
		if (strcmp(cmd->command, "exit") == 0)
		{
			free_all(cmd);
			exit(EXIT_SUCCESS);
		}

		if (strcmp(cmd->command, "env") == 0)
		{
			while (*envs)
			{
				printf("%s\n", *envs);
				envs++;
			}
			free_all(cmd);
			continue;
		}

		if (strcmp(cmd->command, "cd") == 0)
		{
			printf("I'm cd command\n");
			free_all(cmd);
			continue;
		}
		// ----------------------------------- no-build-in-functions----------------------

		/**
		 * Extract the command path
		 *
		 */
		commandPath = get_path_from_command(cmd, envPath);
		if (!commandPath)
		{
			printf("%s: command not found\n", cmd->command);
			free(commandPath);
			free_all(cmd);
			continue;
		}

		pid_t childPid = fork();
		int statusLock;

		if (childPid == 0)
		{
			// cmd->num_flags;
			// ([ arg1, arg2, arg3 ]) = 3;
			int totalCommand = cmd->num_flags + 1;

			char **arg_list = malloc(sizeof(char *) * totalCommand);

			int i = 0;
			while (i < totalCommand)
			{
				if (i == 0)
					arg_list[i] = commandPath;
				else
					arg_list[i] = cmd->flags[i - 1];
				i++;
			}

			// [command, arg1, arg2, arg3] = 4

			// arg_list = [command] || cmd->flags = [arg1, arg2, arg3]
			// [1] + [2] = [1, 2];
			// [command, arg1, arg2, arg3]
			// execv(..., arg_list)
			execv(commandPath, arg_list);
		}

		wait(&statusLock);

		// implement execv

		// ----------------------------------- no-build-in-functions----------------------

		// Func that free all mallocs
		free(commandPath);
		free_all(cmd);
	}

	return (EXIT_SUCCESS);
}
