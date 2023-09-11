#ifndef DOG_H
#define DOG_H

/**
 * struct dog - Defines a structure called 'dog'
 * @name: The name of the dog (string)
 * @age: The age of the dog (float)
 * @owner: The owner of the dog (string)
 *
 * Description: This structure defines a dog with a name, age, and owner.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif
