#include "shell.h"
/**
 * _strdup - string duplicate
 * @str: string
 * Return: pointer to string
 */
char *_strdup(const char *str)
{
	char *point;
	int a, ln = 0;

	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		ln++;
		str++;
	}
	str = str - ln;
	point = malloc(sizeof(char) * (ln + 1));
	if (point == NULL)
		return (NULL);
	for (a = 0; a <= ln; a++)
		point[a] = str[a];
	return (point);
}

/**
 * _strcmp - concatenates string
 * @s1: first string
 * @s2: second string
 * Return: bytes
 */
int _strcmp(char *s1, char *s2)
{
	int cp;

	cp = (int)*s1 - (int)*s2;
	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
		cp = (int)*s1 - (int)*s2;
	}
	return (cp);
}

/**
 * _strlen - length of a string
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
	int ln = 0;

	while (s[ln])
		ln++;
	return (ln);
}

/**
 * _strcat - concatenates string
 * @dest: dest
 * @src: source
 * Return: string
 */
char *_strcat(char *dest, char *src)
{
	char *n = dest;

	while (*n)
		n++;
	while (*src)
	{
		*n = *src;
		n++;
		src++;
	}
	*n = *src;
	return (dest);
}

/**
 * _strcpy - copies string
 * @dest: dest
 * @src: source
 * Return: string copied
 */
char *_strcpy(char *dest, char *src)
{
	int l = 0;

	while (src[l])
	{
		dest[l] = src[l];
		l++;
	}
	return (dest);
}
