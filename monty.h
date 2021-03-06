#ifndef _MONTY_H_
#define _MONTY_H_
/* standard libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/* Structures */
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
 * struct instruction_s - opcode and its function
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

/*global variables*/
extern char **token_arr;
char **token_arr;
/*functions*/
char **strtok_arr(char *str, char *delim);
int find_delimiter(char *delim, char str_char);
int token_counter(char *str, char *delim);
void *_calloc(unsigned int nmemb, unsigned int size);
void free_arr(char **arr);
instruction_t functions_list(int i);
void _push(stack_t **stack, unsigned int line_number);
int arr_len(void);
void free_dlistint(stack_t **head);
int is_number(void);
void free_failure(stack_t *head, char *line_buf, FILE *fp);
void free_success(stack_t *head, char *line_buf, FILE *fp);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
FILE *check_start(int ac, char **av);
#endif
