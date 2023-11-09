0x17. C - Doubly linked lists

Learning Objectives
General
What is a doubly linked list
How to use doubly linked lists
Understand and know how to implement the various operations (deletion, insertion, etc) with doubly linked lists
Start to look for the right source of information without too much help

Requirements
General
Allowed editors: vi, vim, emacs
All your files will be interpreted/compiled on Ubuntu 20.04 LTS using python3 (version 3.8.5)
All your files should end with a new line
A README.md file, at the root of the folder of the project is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
You are not allowed to use global variables
No more than 5 functions per file
The only C standard library functions allowed are malloc, free, printf and exit
In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
The prototypes of all your functions should be included in your header file called lists.h
Don’t forget to push your header file
All your header files should be include guarded

More Info
Please use this data structure for this project:

/**
 * struct dlistint_s - doubly linked list
 * @n: integer
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 *
 */
typedef struct dlistint_s
{
	int n;
	struct dlistint_s *prev;
	struct dlistint_s *next;
} dlistint_t;


Quiz questions
Question #0
In a doubly linked list, what are possible directions to traverse it? (select all possible answers)
---Backward
---Forward

Question #1
In a doubly linked list, what’s the “head” of a linked list?
---It’s the node with the pointer to the previous equals to NULL
---It’s the node with the pointer to the next equals to NULL


Tasks
0. Print list
Write a function that prints all the elements of a dlistint_t list.
Prototype: size_t print_dlistint(const dlistint_t *h);
Return: the number of nodes
Format: see example
File: 0-print_dlistint.c, 0-main.c

1. List length
Write a function that returns the number of elements in a linked dlistint_t list.
Prototype: size_t dlistint_len(const dlistint_t *h);
File: 1-dlistint_len.c, 1-main.c

2. Add node
Write a function that adds a new node at the beginning of a dlistint_t list.
Prototype: dlistint_t *add_dnodeint(dlistint_t **head, const int n);
Return: the address of the new element, or NULL if it failed
File: 2-add_dnodeint.c, 1-main.c

3. Add node at the endWrite a function that adds a new node at the end of a dlistint_t list.
Prototype: dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);
Return: the address of the new element, or NULL if it failed
File: 3-add_dnodeint_end.c, 3-main.c

4. Free list
Write a function that frees a dlistint_t list.
Prototype: void free_dlistint(dlistint_t *head);
File: 4-free_dlistint.c, 4-main.c

5. Get node at index
Write a function that returns the nth node of a dlistint_t linked list.
Prototype: dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index);
where index is the index of the node, starting from 0
if the node does not exist, return NULL
File: 5-get_dnodeint.c, 5-main.c

6. Sum list
Write a function that returns the sum of all the data (n) of a dlistint_t linked list.
Prototype: int sum_dlistint(dlistint_t *head);
if the list is empty, return 0
File: 6-sum_dlistint.c, 6-main.c

7. Insert at index
Write a function that inserts a new node at a given position.
Prototype: dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n);
where idx is the index of the list where the new node should be added. Index starts at 0
Returns: the address of the new node, or NULL if it failed
if it is not possible to add the new node at index idx, do not add the new node and return NULL
Your files 2-add_dnodeint.c and 3-add_dnodeint_end.c will be compiled during the correction
File: 7-insert_dnodeint.c, 2-add_dnodeint.c, 3-add_dnodeint_end.c, 7-main.c

8. Delete at index
Write a function that deletes the node at index index of a dlistint_t linked list.
Prototype: int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);
where index is the index of the node that should be deleted. Index starts at 0
Returns: 1 if it succeeded, -1 if it failed
File: 8-delete_dnodeint.c, 8-main.c

9. Crackme4
Find the password for crackme4.
Save the password in the file 100-password
Your file should contain the exact password, no new line, no extra space
Hint: The program prints “OK” when the password is correct
File: 100-password

10. Palindromes
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 x 99.
Find the largest palindrome made from the product of two 3-digit numbers.
---Save the result in the file 102-result
---Your file should contain the exact result, no new line, no extra space
File: 102-result

11. crackme5
Write a keygen for crackme5.
Usage of the crackme: ./crackme5 username key
The crackme will segfault if you do not enter the correct key for the user
Usage for your keygen: ./keygen5 username
Your keygen should print a valid key for the username
File: 103-keygen.c

julien@ubuntu:~/0x17$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 103-keygen.c -o keygen5
julien@ubuntu:~/0x17$ ./crackme5 julien javascript
Segmentation fault (core dumped)
julien@ubuntu:~/0x17$ ./crackme5 julien `./keygen5 julien`
Congrats!
julien@ubuntu:~/0x17$