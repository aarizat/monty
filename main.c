#include "monty.h"

char **token_arr;
char *line_buf;
FILE *fp;
int main(int argc, char **argv)
{
	size_t buf_size = 0;
	int i, line_size = 0;
	unsigned int line_count = 0;
	instruction_t valid_instructions[4];
	stack_t *head = NULL;

	line_buf = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < 4; i++)
		valid_instructions[i] = functions_list(i);
	line_size = getline(&line_buf, &buf_size, fp);
	while (line_size != -1)
	{
		line_count++;
		if (line_size != 1)
		{
			token_arr = strtok_arr(line_buf, " \n");
			for (i = 0; i < 4; i++)
			{
				if (!strcmp(valid_instructions[i].opcode, token_arr[0]))
				{
					valid_instructions[i].f(&head, line_count);
					break;
				}
			}
			if (i == 4)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_count, token_arr[0]);
				free_failure(head);
			}
			free_arr(token_arr);
		}
		line_size = getline(&line_buf, &buf_size, fp);
	}
	free_success(head);
	return (0);
}


instruction_t functions_list(int i)
{
	instruction_t functions[] = {{"push", _push},
				     {"pall", _pall},
				     {"pint", _pint},
				     {"pop", _pop}
//				    {"pall", _pall},{"pint", _pint},
//				    {"swap", _swap},{"add", _add},
//				    {"nop", _nop}, {"sub", _sub},
//				    {"div", _div}, {"mul", _mul},
//				    {"mod", _mod}, {"pchar", _pchar},
//				    {"pstr", _pstr}, {"rotl", _rotl},
//				    {"rotr", _rotr}, {"stack", _stack},
//				    {"queue", _queue}
	};
	return (functions[i]);
}
