#include "monty.h"

/**
 * _sub - substracts the two top elements on the stack
 * @stack: head
 * @line_number: line number.
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->next;
		tmp->n -= (*stack)->n;
		tmp->prev = NULL;
		free(*stack);
		*stack = tmp;
	}
	else
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_failure(*stack);
	}
}

/**
* _mul - multiplies the two top elements on the stack
* @stack: head
* @line_number: line number.
*/

void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->next;
		tmp->n *= (*stack)->n;
		tmp->prev = NULL;
		free(*stack);
		*stack = tmp;
	}
	else
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_failure(*stack);
	}
}

/**
 * _div - divides the two top elements on the stack
 * @stack: head
 * @line_number: line number.
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack && (*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L<line_number>: division by zero",
				line_number);
			free_failure(*stack);
		}
		tmp = (*stack)->next;
		tmp->n /= (*stack)->n;
		tmp->prev = NULL;
		free(*stack);
		*stack = tmp;
	}
	else
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
			line_number);
		free_failure(*stack);
	}
}

/**
 * _mod - modss the two top elements on the stack
 * @stack: head
 * @line_number: line number.
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack && (*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L<line_number>: division by zero",
				line_number);
			free_failure(*stack);
		}
		tmp = (*stack)->next;
		tmp->n %= (*stack)->n;
		tmp->prev = NULL;
		free(*stack);
		*stack = tmp;
	}
	else
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
			line_number);
		free_failure(*stack);
	}
}
