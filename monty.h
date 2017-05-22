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
#include <string.h>
#include <ctype.h>

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
 * @filename: the filename from argv[1]
 * @stack: pointer to stack
 * @line: input line received from getline
 * @input: lines of the files parsed into separate elements
 * @linenum: the linenumber
 */
typedef struct inventory_s
{
	char *filename;
	stack_t *stack;
	char *line;
	char **input;
	unsigned int linenum;
}inventory_t;

extern inventory_t *inventory;
inventory_t *inventory;

/* ------Built Inventory -------*/

int build_inventory();

/* ----- Stack ----- */

void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
/* ----- Mem Alloc ----- */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_calloc(unsigned int nmemb, unsigned int size);

/* ----- Execute ------ */

void (*match_opcode(void))(stack_t **stack, unsigned int line_number);
int parse_line(char *line);
int are_digits(char *num);

/* ----- Finish ----- */

void free_all(void);
void free_stack(void);
int find_error(char *error);
void handle_errors(char *error);

#endif
