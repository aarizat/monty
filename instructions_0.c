#include "monty.h"

/**
 * _push - pushes an element to sttack
 * @stack: pointer to first node of the doubly linked list.(stack).
 * @line_number: number of line where is find push instruction.
 *
 * Return: nothing.
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	if (arr_len() != 2)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_failure(*stack);
	}
	else
	{
		if (!is_number())
		{
			fprintf(stderr, "L%u: usage: push integer\n",
				line_number);
			free_failure(*stack);
		}
	}
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		return;
	new_node->n = atoi(token_arr[1]);
	new_node->prev = NULL;
	new_node->next = NULL;
	if (!*stack)
		*stack = new_node;
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}
/**
 * _pall - prints all values on the stack.
 * @stack: pointer to first node of the  doubly linked list. (stack).
 * @line_number: number of line where is find pall instruction.
 *
 * Return: nothing.
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	stack_t *aux = *stack;

	for (; aux != NULL; aux = aux->next)
		printf("%d\n", aux->n);
}
/**
 * _pint - prints the value at the top of the stack.
 * @stack: pointer to first node of the  doubly linked list. (stack).
 * @line_number: number of line where is find pint instruction.
 *
 * Return: nothing.
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * _pop - removes the top element of the stack.
 * @stack: pointer to first node of the  doubly linked list. (stack).
 * @line_number: number of line where is find pop instruction.
 *
 * Return: nothing.
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	if (!aux)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_arr(token_arr);
		fclose(fp);
		free(line_buf);
		exit(EXIT_FAILURE);
	}
	else if (!aux->next)
	{
		free(aux);
		*stack = NULL;
	}
	else
	{
		aux = aux->next;
		free(*stack);
		*stack = aux;
		(*stack)->prev = NULL;
	}
}
