#ifndef _MONTY_H_
#define _MONTY_H_
/* standard libraries*/
#include <stdio.h>
#include <stdlib.h>
/*functions*/
char **strtok_arr(char *str, char *delim);
int find_delimiter(char *delim, char str_char);
int token_counter(char *str, char *delim);
void *_calloc(unsigned int nmemb, unsigned int size);
void free_arr(char **arr);
#endif
