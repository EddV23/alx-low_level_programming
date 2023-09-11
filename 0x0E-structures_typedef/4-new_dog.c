#include <stdlib.h>
#include "dog.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 *           which contains a copy of the string given as a parameter
 * @str: the string to duplicate.
 *
 * Return: A pointer to the duplicated string, or
 *         NULL if str is NULL or if memory allocation fails
 */
char *_strdup(char *str)
{
	char *duplicate;
	unsigned int i, length = 0;

	if (str == NULL)
		return (NULL);

	while (str[length] != '\0')
		length++;

	duplicate = malloc(sizeof(char) * (length + 1));

	if (duplicate == NULL)
		return (NULL);

	for (i = 0; i <= length; i++)
		duplicate[i] = str[i];

	return (duplicate);
}

/**
 * new_dog - creates a new dog and stores a copy of name and owner
 * @name:name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: Pointer to the newly created dog, or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog_ptr;
	char *name_copy, *owner_copy;

	new_dog_ptr = malloc(sizeof(dog_t));
	if (new_dog_ptr == NULL)
		return (NULL);
	name_copy = _strdup(name);
	owner_copy = _strdup(owner);
	if (name_copy == NULL || owner_copy == NULL)
	{
		free(name_copy);
		free(owner_copy);
		free(new_dog_ptr);
		return (NULL);
	}
	new_dog_ptr->name = name_copy;
	new_dog_ptr->age = age;
	new_dog_ptr->owner = owner_copy;
	return (new_dog_ptr);
}
