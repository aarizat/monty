#include "monty.h"
/**
 * free_failure - free all allocated slot on the heap when the program fail.
 * @head: pointer to first node in the stack.
 *
 * Return: nothing.
 */
void free_failure(stack_t *head)
{
	free_arr(token_arr);
	free(line_buf);
	free_dlistint(&head);
	fclose(fp);
	exit(EXIT_FAILURE);
}

/**
 * free_success - free all allocated slot on the heap when the program success.
 * @head: pointer to first node in the stack.
 *
 * Return: nothing.
 */
void free_success(stack_t *head)
{
	free(line_buf);
	free_dlistint(&head);
	fclose(fp);
}
