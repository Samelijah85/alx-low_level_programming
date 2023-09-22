#include "main.h"

/**
 * rev_string - reverse array
 * @n: pointer to the character array
 */
void rev_string(char *n)
{
    int i = 0, j = 0;
    char temp;

    while (*(n + i) != '\0')
    {
        i++;
    }
    i--;

    for (j = 0; j < i; j++, i--)
    {
        temp = *(n + j);
        *(n + j) = *(n + i);
        *(n + i) = temp;
    }
}

/**
 * infinite_add - add two numbers together
 * @n1: text representation of the first number
 * @n2: text representation of the second number
 * @r: pointer to the buffer to store the result
 * @size_r: size of the buffer
 * Return: pointer to the result string
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int overflow = 0, i = 0, j = 0, digits = 0;
    int val1 = 0, val2 = 0, temp_tot = 0;

    while (*(n1 + i) != '\0')
        i++;
    while (*(n2 + j) != '\0')
        j++;
    i--;
    j--;
    
    if (j >= size_r || i >= size_r || size_r <= 0)
        return (0);
    
    while (j >= 0 || i >= 0 || overflow == 1)
    {
        if (i < 0)
            val1 = 0;
        else
            val1 = *(n1 + i) - '0';
        if (j < 0)
            val2 = 0;
        else
            val2 = *(n2 + j) - '0';
        
        temp_tot = val1 + val2 + overflow;
        overflow = temp_tot / 10;
        temp_tot %= 10;
        
        if (digits + 1 >= size_r)
            return (0);
        else
            *(r + digits) = temp_tot + '0';
        
        digits++;
        i--;
        j--;
    }
    
    if (digits >= size_r)
        return (0);
    else
    {
        if (overflow == 1)
        {
            if (digits + 1 >= size_r)
                return (0);
            else
            {
                *(r + digits) = '1';
                digits++;
            }
        }
        *(r + digits) = '\0';
        rev_string(r);
        return (r);
    }
} 
