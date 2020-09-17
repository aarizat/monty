#include "monty.h"

void free_failure(stack_t *head)
{
	free_arr(token_arr);
        free(line_buf);
        free_dlistint(&head);
        fclose(fp);
        exit(EXIT_FAILURE);
}

void free_success(stack_t *head)
{
	free(line_buf);
        free_dlistint(&head);
        fclose(fp);
}
