#include "monty.h"

int main(int argc, char **argv)
{
	char *line_buf = NULL;
	size_t buf_size = 0;
	size_t line_size = 0;
	unsigned int line_count = 0;
	FILE *fp;
	extern char **token_arr;
	int i;
	instruction_t valid_instructions[17];
	stack_t **head = NULL;

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
	for (i = 0; i < 16; i++)
	  valid_instructions[i] = functions_list(i);
	line_size = getline(&line_buf, &buf_size, fp);
	while (line_size != -1)
	{
		line_count++;
		token_arr = strtok_arr(line_buf, " \n");
		for (i = 0; token_arr[i]; i++)
			printf("%s\n", token_arr[i]);
		free_arr(token_arr);
		token_arr = NULL;
		/*printf("line %d -->  %s", line_count, line_buf);*/
		line_size = getline(&line_buf, &buf_size, fp);
	}
	free(line_buf);
	line_buf = NULL;
	fclose(fp);
	return (0);
}


instruction_t functions_list(int i)
{
  intruction_t functions[] = {{"pop", _pop},
							  {"push", _push},
							  {"pall", _pall},
							  {"pint", _pint},
							  {"swap", _swap},
							  {"add", _add},
							  {"nop", _nop},
							  {"sub", _sub},
							  {"div", _div},
							  {"mul", _mul},
							  {"mod", _mod},
							  {"pchar", _pchar},
							  {"pstr", _pstr},
							  {"rotl", _rotl},
							  {"rotr", _rotr},
							  {"stack", _stack},
							  {"queue", _queue}};
  return (functions[i]);
}

