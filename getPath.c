#include "my_shell.h"
/**
 * getpath_sll - Get the path from Command object
 * @sll: Command
 * @envPath: environment path
 * Return: char*
 */
char *getpath_sll(sll_t *sll, char *envPath)
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
		path = _strconcat(token, "/", sll->Command);

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
