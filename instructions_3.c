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
		/*free_failure(*stack);*/
		free_arr(token_arr);
		return;
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
		/*free_failure(*stack);*/
		free_arr(token_arr);
		return;
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
			fprintf(stderr, "L%u: division by zero\n",
				line_number);
			/*free_failure(*stack);*/
			free_arr(token_arr);
			return;
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
		/*free_failure(*stack);*/
		free_arr(token_arr);
		return;
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
			fprintf(stderr, "L%u: division by zero\n",
				line_number);
			/*free_failure(*stack);*/
			free_arr(token_arr);
			return;
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
		/*free_failure(*stack);*/
		free_arr(token_arr);
		return;
	}
}
