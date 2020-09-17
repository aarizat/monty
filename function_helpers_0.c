#include "monty.h"
/**
 *_calloc - Mimics calloc function using malloc.
 *@nmemb: number of elements of the allocated memory block.
 *@size: size of each element of the block.
 *
 *Return: Pointer to the allocated memory, NULL if fails.
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *p;
	char *ptr;
	unsigned int i, block_size;

	if (nmemb == 0 || size == 0)
		return (NULL);

	p = malloc(nmemb * size);
	if (p == NULL)
		return (p);

	block_size = nmemb * size;
	ptr = p;
	for (i = 0; i < block_size; i++)
		ptr[i] = 0;
	return (p);
}
/**
 * free_arr - frees an array of ppointers.
 * @arr: pointer to first elements of the array.
 *
 * Return: nothing.
 */
void free_arr(char **arr)
{
	int i = 0;

	for (; arr[i]; i++)
		free(arr[i]);
	free(arr);
}
/**
 * arr_len - calcaultes the lenght of array.
 *
 * Return: lenght of the array.
 */
int arr_len()
{
	int len = 0;

	for (; token_arr[len]; len++)
	{}
	return (len);
}
/**
 * free_dlistint - free all of nodes of double linked list.
 * @head: pointer to first node.
 *
 * Return: nothing.
 */
void free_dlistint(stack_t **head)
{
	stack_t *aux;

	if (*head == NULL)
		return;
	while (*head != NULL)
	{
		aux = (*head)->next;
		free(*head);
		*head = aux;
	}
	*head = NULL;
}
/**
 * is_number - checks if a given string can be converted to integer number.
 *
 * Return: nothing.
 */
int is_number()
{
	int i = 0;

	if (!token_arr[1])
		return (0);
	for (; token_arr[1][i]; i++)
	{
		if (!isdigit(token_arr[1][i]))
			return (0);
	}
	return (1);
}
