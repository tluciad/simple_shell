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
	char *CommandPath = NULL, *envPath;

	envPath = getenv("PATH");

	signal(SIGINT, new_signal_handler);/*SIGINT = Interrupt the process*/

	while (true)
	{
		line = NULL;
		CommandPath = NULL;
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
		printf("Command: |%s|\n", cmd->Command);
		
		if (strcmp(cmd->Command, "exit") == 0)
		{
			free_all(cmd);
			exit(EXIT_SUCCESS);
		}

		if (strcmp(cmd->Command, "env") == 0)
		{
			while (*envs)
			{
				printf("%s\n", *envs);
				envs++;
			}
			free_all(cmd);
			continue;
		}
		
		CommandPath = getpath_cmd(cmd, envPath);
		if (!CommandPath)
		{
			printf("%s: Command not found\n", cmd->Command);
			free(CommandPath);
			free_all(cmd);
			continue;
		}

		pid_t childPid = fork();
		int statusLock;

		if (childPid == 0)
		{
			
			int totalCommand = cmd->num_flags + 1;

			char **arg_list = malloc(sizeof(char *) * totalCommand);

			int i = 0;
			while (i < totalCommand)
			{
				if (i == 0)
					arg_list[i] = CommandPath;
				else
					arg_list[i] = cmd->flags[i - 1];
				i++;
			}

			execv(CommandPath, arg_list);
		}

		wait(&statusLock);

		free(CommandPath);
		free_all(cmd);
	}

	return (EXIT_SUCCESS);
}
