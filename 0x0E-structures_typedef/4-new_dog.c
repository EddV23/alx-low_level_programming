#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dog.h"

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

	name_copy = strdup(name);
	if (name_copy == NULL)
	{
		free(new_dog_ptr);
		return (NULL);
	}

	owner_copy = strdup(owner);
	if (owner_copy == NULL)
	{
		free(name_copy);
		free(new_dog_ptr);
		return (NULL);
	}

	new_dog_ptr->name = name_copy;
	new_dog_ptr->age = age;
	new_dog_ptr->owner = owner_copy;

	return (new_dog_ptr);
}
