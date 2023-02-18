#include "main.h"

/**
 * _strcat - a function that concatenates two strings.
 * @str1: first string.
 * @str2: second string to be concatenated.
 * Return: pointer to the concatenated string.
 */
char *_strcat(char *str1, char *str2)
{
	char *concatstring;
	int len1 = _strlen(str1), len2 = _strlen(str2), iterator1, iterator2;

	concatstring = malloc(sizeof(char) * (len1 + len2 + 1));
	if (concatstring == NULL)
	{
		printf("Error: impossible to allocate memory");
		exit(98);
	}
	for (iterator1 = 0; str1[iterator1] != '\0'; iterator1++)
	{
		concatstring[iterator1] = str1[iterator1];
	}
	for (iterator2 = 0; str2[iterator2] != '\0'; iterator2++)
	{
		concatstring[iterator1 + iterator2] = str2[iterator2];
	}
	concatstring[iterator1 + iterator2] = '\0';
	return (concatstring);
}

/**
 * _strcmp - a function that compares two strings.
 * @s1: string one.
 * @s2: string two.
 * Return: 0 if match, anything else if they don't match.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0, c = 0, greater;
	int len1, len2;

	if (!s1 || !s2)
		return (-1);

	len1 = _strlen(s1);
	len2 = _strlen(s2);

	if (!len1 || !len2)
		return (-1);

	while (s1[i] != 0 && s2[i] != 0)
	{
		if (s1[i] == s2[i])
		{
			c++;
		}
		i++;
	}
	greater = len1 > len2 ? len1 : len2;
	if (c == greater)
		return (0);
	return (-1);
}

/**
 * _strcpy - a function that prints string.
 * Return: length of string
 * @dest: destiny string
 * @src: source string
 */
char *_strcpy(char *dest, char *src)
{
	int s = 0;

	int i;

	while (src[s] != 0)
	{
		s++;
	}

	dest[s] = '\0';
	for (i = 0; i < s; i++)
		dest[i] = src[i];

	return (dest);
}
/**
 * _strdup - a function that gives a pointer to memory space.
 * @str: string.
 * Return: pointer.
 */
char *_strdup(char *str)
{
	char *s;

	unsigned int size = 0, i;

	if (str == NULL)
		return (NULL);

	while (*(str + size))
		size++;

	s = malloc(sizeof(char) * (size + 1));

	if (s == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		*(s + i) = *(str + i);

	*(s + size) = '\0';
	return (s);
}
/**
 * _strlen - a function that len of string.
 * Return: length of string.
 * @s: string.
 */
int _strlen(char *s)
{
	int counter = 0;

	if (!s)
		return (counter);

	while (s[counter] != 0)
		counter++;
	return (counter);
}
