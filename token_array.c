#include "monty.h"

/**
 * token_counter - Counts the number of words that can be tokenized using
 * the delimiters.
 * @str: Input from main function, string to be tokenized
 * @delim: Delimeters to split strings
 * Return: Number of strings
 */

int token_counter(char *str, char *delim)
{
  int i, j;
  int str_delim = 0, flag = 0, count = 0;

  for (i = 0; str[i]; i++)
	{
	  for (j = 0; delim[j]; j++)
		{
		  if (str[i] == delim[j])
			{
			  str_delim = 1;
			  flag = 0;
			  break;
			}
		  str_delim = 0;
		}
	  if (str_delim == 0 && flag == 0)
		{
		  flag = 1;
		  count++;
		}
	}
  return (count);
}

/**
 * strtok_arr - Creates an Array of strings from the input
 * @str: Input from main function, string to be tokenized
 * @delim: Delimeters to split strings
 * Return: Array of strings
 */

char **strtok_arr(char *str, char *delim)
{
  char *copy = NULL, **token_array = NULL;
  int i = 0, j = 0, len = 0, count = 0, str_delim = 0, copy_delim = 0;

  if (str == 0 || *str == 0)
	return (NULL);
  count = token_counter(str, delim);
  if (count == 0)
	return (NULL);
  /*token_array = _calloc((count + 1), sizeof(char *));*/
  token_array = malloc(sizeof(char *) * (count + 1));
  if (token_array == NULL)
	return (NULL);
  while (*str && i < count)
	{
	  str_delim = find_delimiter(delim, *str);
	  if (str_delim == 1)
		str++;
	  else
		{
		  copy = str;
		  while (str_delim == 0 && *str)
			str_delim = find_delimiter(delim, *str), len++, str++;
		  /*token_array[i] = _calloc((len + 1), sizeof(char));*/
		  token_array[i] = malloc(sizeof(char) * (len + 1));
		  if (!token_array[i])
			return (NULL);
		  while (*copy && *copy != '\n')
			{
			  copy_delim = find_delimiter(delim, *copy);
			  if (copy_delim == 0)
				token_array[i][j] = *copy, copy++, j++;
			  else
				break;
			}
		  token_array[i][j] = '\0', i++, j = 0, len = 0;
		}
	}
  token_array[i] = NULL;
  return (token_array);
}

/**
 * find_delimiter - Find the delimiter in the string
 * @str_char: Input from main function, string to be tokenized
 * @delim: Delimeters to split strings
 * Return: 1 if it found the delimiter inside de string, else 0
 */

int find_delimiter(char *delim, char str_char)
{
  int i, is_delim;

  for (i = 0; delim[i]; i++)
	{
	  if (str_char == delim[i])
		{
		  is_delim = 1;
		  break;
		}
	  is_delim = 0;
	}
  return (is_delim);
}
