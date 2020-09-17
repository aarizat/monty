#include "monty.h"

/**
 * _swap - Swaps the top two elements if the stack
 * @stack: head of stack
 * @line_number: line number
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->next;
		if ((*stack)->next->next)
		{
			tmp->next->prev = *stack;
			(*stack)->prev = tmp;
			(*stack)->next = tmp->next;
			tmp->next = *stack;
			tmp->prev = NULL;
		}
		else
		{
			tmp->next = *stack;
			(*stack)->prev = tmp;
			tmp->prev = NULL;
			(*stack)->next = NULL;
		}
		*stack = tmp;
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
			line_number);
		/*free_failure(*stack);*/
		free_arr(token_arr);
		return;
	}
}

/**
 * _add - adds the two top elements on the stack
 * @stack: head
 * @line_number: line number.
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->next;
		tmp->n += (*stack)->n;
		tmp->prev = NULL;
		free(*stack);
		*stack = tmp;
	}
	else
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		/*free_failure(*stack);*/
		free_arr(token_arr);
		return;
	}
}

/**
* _nop - Does nothing.
* @stack: head of stack.
* @line_number: line number.
*/

void _nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
