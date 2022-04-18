#include "my_shell.h"
/**
 * getpath_cmd - Get the path from Command object
 * @cmd: Command
 * @envPath: environment path
 * Return: char*
 */
char *getpath_cmd(sll_t *cmd, char *envPath)
{
	char *path = NULL,
			 *token = NULL,
			 *tempEnvP = NULL,
			 *tempToken = NULL;
	struct stat stats;

	tempEnvP = _strdup(envPath);

	token = strtok(tempEnvP, ":");
	while (token != NULL)
	{
		path = _strconcat(token, "/", cmd->Command);

		if (stat(path, &stats) == 0)
			break;

		free(path);
		path = NULL;
		token = strtok(NULL, ":");
	}

	free(tempEnvP);

	if (!path)
		return (NULL);
	return (path);
}
