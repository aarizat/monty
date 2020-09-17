#include "monty.h"

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
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
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
