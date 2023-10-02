#include "main.h"
#include <stdlib.h>
/**
 *create _array - create array of size size and assign char c 
 *size: size of array
 *@c: chat to assign
 *Description: create array of size size and assign char c
 * Return: pointer to array, NULL if fail 
 *
 */
char *create_array(unsigned int size, chat c)
{

	Char *str; 
        unsigned int i;

	str = malloc(sizeof(char) *size);
	If(size == 0 || st == NULL)
             return (NULL);

	for (i = 0; I < size; i++)
              str[i] = c;
	return (str);
}
