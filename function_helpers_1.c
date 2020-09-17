#include "monty.h"

/**
 * check_start - verify the beginnig of the program.
 * @ac: number of argument to the program.
 * @av: array of arguments of the program.
 *
 * Return: nothing.
 */

FILE *check_start(int ac, char **av)
{
	FILE *fp;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(av[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s", av[1]);
		exit(EXIT_FAILURE);
	}
	return (fp);
}

/**
 * free_failure - free all allocated slot on the heap when the program fail.
 * @head: pointer to first node in the stack.
 * @line_buf: line
 * @fp: file pointer˙
 * Return: nothing.
 */

void free_failure(stack_t *head, char *line_buf, FILE *fp)
{
	/*free_arr(token_arr);*/
	free(line_buf);
	free_dlistint(&head);
	fclose(fp);
	exit(EXIT_FAILURE);
}

/**
 * free_success - free all allocated slot on the heap when the program success.
 * @head: pointer to first node in the stack.
 * @line_buf: line.
 * @fp: file pointer.
 * Return: nothing.
 */
void free_success(stack_t *head, char *line_buf, FILE *fp)
{
	free(line_buf);
	free_dlistint(&head);
	fclose(fp);
}
