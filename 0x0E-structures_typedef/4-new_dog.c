#include "dog.h"
#include <stdlib.h>

int slen(char *s);
char *_strcopy(char *dest, char *src);
dog_t *new_dog(char *name, float age, char *owner);

/**
 * slen - gets the length of a string
 * @s: given string
 *
 * Return: length of the string
 */
int slen(char *s)
{
	int i = 0, len = 0;

	while (s[i] != '\0')
	{
		len++;
		i++;
	}

	return (len);
}

/**
 * _strcpy - Copies a string from source src to buffer dest
 * @dest: buffer storing copy of string
 * @src: the source string
 *
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}

/**
 * new_dog - creates a new dog.
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 * Return: new dog_t.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *ndog;

	if (name == NULL || age < 0 || owner == NULL)
		return (NULL);

	ndog = malloc(sizeof(dog_t));
	if (ndog == NULL)
		return (NULL);

	ndog->name = malloc(sizeof(char) * (slen(name) + 1));
	if (ndog->name == NULL)
	{
		free(ndog);
		return (NULL);
	}

	ndog->owner = malloc(sizeof(char) * (slen(owner) + 1));
	if (ndog->owner == NULL)
	{
		free(ndog->name);
		free(ndog);
		return (NULL);
	}

	ndog->name = _strcpy(ndog->name, name);
	ndog->age = age;
	ndog->owner = _strcpy(ndog->owner, owner);

	return (ndog);
}
