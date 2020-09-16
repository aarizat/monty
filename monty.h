#ifndef _MONTY_H_
#define _MONTY_H_
/* standard libraries*/
#include <stdio.h>
#include <stdlib.h>
/*functions*/
char **strtok_arr(char *str, char *delim);
int find_delimiter(char *delim, char str_char);
int token_counter(char *str, char *delim);
void *_calloc(unsigned int nmemb, unsigned int size);
void free_arr(char **arr);
void _pop(stack_t **stack, unsigned int line_number);
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

#endif
