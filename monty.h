#ifndef _MONTY_H_
#define _MONTY_H_

/* ----- c std lib headers ----- */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>

/* ----- macros ----- */

#define TRUE (1 == 1)
#define FALSE (!TRUE)
#define BUFSIZE 1024

/* ----- Structs ----- */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * inventory_s - a struct pointing to all other structs for this project
 * @stack: pointer to stack
 * @instruct: the instruction pointer, function pointers
 * @input: lines of the files parsed into separate elements
 */
typedef struct inventory_s
{
	stack_t **stack;
	instruction_t *instruct;
	char **input;
	unsigned int linenum;
}inventory_t;

extern inventory_t *inventory;
inventory_t *inventory;

/* ----- Parse File ----- */
inputs_t *parse_input(char *buffer);

/* ----- Stack ----- */

void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);

/* ----- Mem Alloc ----- */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_calloc(unsigned int nmemb, unsigned int size);

/* ----- Execute ------ */

void (*execute_opcode(char *s))(stack_t **stack, unsigned int line_number);

/* ------Built Inventory -------*/
int allocate_inventory();
int build_inventory();

#endif
