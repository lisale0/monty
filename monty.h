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
 * struct inputs_s - linked list representation input commands
 * @line: an input line
 * @next: points to the next element (or command line) of list
 */
typedef struct inputs_s
{
        char *line;
        struct inputs_s *next;
} inputs_t;

/* ----- Strings ----- */

int _strlen(char *s);
int _strncmp(char *s1, char *s2, unsigned int n);

/* ----- Write ----- */

void _puts(char *str);
int _putchar(char c);
int write_uint(unsigned int n);

/* ----- File I/O ----- */

char *read_monty(const char *filename);

/* ----- Stack ----- */

void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);

/* ----- Mem Alloc ----- */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_calloc(unsigned int nmemb, unsigned int size);

/* ----- Execute ------ */

void (*execute_opcode(char *s))(stack_t **stack, unsigned int line_number);

#endif
