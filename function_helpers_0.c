#include "monty.h"

/**
 *_calloc - Mimics calloc function using malloc.
 *@nmemb: number of elements of the allocated memory block.
 *@size: size of each element of the block.
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

void free_arr(char **arr)
{
	int i = 0;

	for (;arr[i]; i++)
		free(arr[i]);
	free(arr);
}
