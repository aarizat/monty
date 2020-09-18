#include "monty.h"

/**
 * main - Entry point
 * @argc: number of arguments for the program.
 * @argv: array of arguments.
 *
 * Return: always 0.
 */
int main(int argc, char **argv)
{
	FILE *fp;
	char *l_buf = NULL;
	size_t buf_size = 0;
	int i, line_size = 0;
	unsigned int l_count = 0;
	instruction_t v_list[11];
	stack_t *head = NULL;

	fp = check_start(argc, argv);
	for (i = 0; i < 11; i++)
		v_list[i] = functions_list(i);
	line_size = getline(&l_buf, &buf_size, fp);
	for (; line_size != -1; line_size = getline(&l_buf, &buf_size, fp))
	{
		l_count++;
		if (line_size != 1)
		{
			token_arr = strtok_arr(l_buf, " \n");
			for (i = 0; i < 11; i++)
			{
				if (!strcmp(v_list[i].opcode, token_arr[0]))
				{
					v_list[i].f(&head, l_count);
					if (!token_arr)
						free_failure(head, l_buf, fp);
					break;
				}
			}
			if (i == 11)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n",
					l_count, token_arr[0]);
				free_arr(token_arr);
				free_failure(head, l_buf, fp);
			}
			free_arr(token_arr);
		}
	}
	free_success(head, l_buf, fp);
	return (0);
}

/**
 * functions_list - structure with all the instrutions for the stack
 * @i: integer number.
 *
 * Return: structure in the specified position.
 */
instruction_t functions_list(int i)
{
	instruction_t functions[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod}
	};
	return (functions[i]);
}
