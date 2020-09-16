#include "monty.h"

int main(int argc, char **argv)
{
	char *line_buf = NULL;
	size_t buf_size = 0;
	size_t line_size = 0;
	unsigned int line_count = 0;
	FILE *fp;
	char **token_arr;
	int i = 0;

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
	line_size = getline(&line_buf, &buf_size, fp);
	while (line_size != -1)
	{
		line_count++;
		token_arr = strtok_arr(line_buf, " ");
		for (; token_arr[i]; i++)
		{
			printf("%s\n", token_arr[i]);
		}
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
