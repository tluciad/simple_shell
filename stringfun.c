#include "my_shell.h"

/**
 * *_strcpy - copies the string pointed to by src to the buffer pointed to dest
 * @dest: char dest
 * @src: char src
 * Return: dest.
 */
char *_strcpy(char *dest, char *src)
{
	int i;
	char a;

	for (i = 0; src[i] != '\0'; i++)
	{
		a = src[i];
		dest[i] = a;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strlen - returns the length of a string.
 * @s: pointer to String
 * Return: Nothing
 */
int _strlen(const char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}

	return (i);
}

char *_strconcat(char *s1, char *s2, char *s3)
{
	char *pstr = NULL;
	unsigned int len, i = 0, current = 0;
	unsigned int x = 0, y = 0, z = 0;

	s1 = s1 ? s1 : EMPTY_STR;
	s2 = s2 ? s2 : EMPTY_STR;
	s3 = s3 ? s3 : EMPTY_STR;

	x = _strlen(s1), y = _strlen(s2), z = _strlen(s3);

	len = x + y + z;
	if (len == 0)
		return (NULL);

	pstr = malloc(sizeof(char) * (len + 1));

	if (pstr == NULL)
		return (NULL);

	for (current = 0; current < x; current++)
		pstr[current] = s1[current];
	for (i = 0; i < y; current++, i++)
		pstr[current] = s2[i];
	for (i = 0; i < z; current++, i++)
		pstr[current] = s3[i];

	pstr[current] = '\0';
	return (pstr);
}

/**
 * _strdup - to duplicate a string 
 * @str: string to duplicate
 * Return: the duplicate. 
 */
char *_strdup(char *str)
{
	char *dup, *j;
	int len = 0;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);

	dup = malloc(len + 1);
	j = dup;

	if (j == NULL)
		return (NULL);

	while (*str)
	{
		*j++ = *str++;
		*j = '\0';
	}

	return (dup);
}

/**
 * _strcmp - compare two strings.
 * @s1: accepts destination string.
 * @s2: accepts source string.
 * Return: pointer to the destination string.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}
