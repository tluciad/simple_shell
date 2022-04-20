#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *_strtok(char *s, char d)
{
	char* input = NULL;
	char* result = NULL;
	new char;
	int i = 0;

	if (s != NULL)
		input = s;

	if (input == NULL)
		return (NULL);

	char *result = new char[strlen(input) + 1];

	while (input[i] != '\0')
		i++;
	{
		if (input[i] != d)
			result[i] = input[i];

		else
		{
			result[i] = '\0';
			input = input + i + 1;
			return (result);
		}
	}
	result[i] = '\0';
	input = NULL;

	return (result);
}

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	// Given string str
	char str[90] = "It, is my, day";

	// Tokenized the first string
	char *ptr = _strtok(str, ' ');

	printf("%s \n", ptr);

	while (ptr != NULL)
	{

		ptr = _strtok(NULL, ' ');

		printf("%s \n", ptr);
	}
	return 0;
}