#include "main.h"

/**
 * Reverse a string.
 * @param str: The string to reverse.
 */
void reverseString(char *str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    length--;

    for (int start = 0, end = length; start < end; start++, end--)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
    }
}

/**
 * Add two infinite numbers represented as strings.
 * @param num1: The first number as a string.
 * @param num2: The second number as a string.
 * @param result: Pointer to the buffer to store the result.
 * @param size: Size of the result buffer.
 * @return Pointer to the result, or NULL in case of an error.
 */
char *addInfiniteNumbers(char *num1, char *num2, char *result, int size)
{
    int overflow = 0, i = 0, j = 0, digits = 0;
    int val1 = 0, val2 = 0, tempSum = 0;

    while (num1[i] != '\0') i++;
    while (num2[j] != '\0') j++;
    i--; j--;

    if (j >= size || i >= size) return NULL;

    while (j >= 0 || i >= 0 || overflow == 1)
    {
        if (i < 0) val1 = 0;
        else val1 = num1[i] - '0';
        if (j < 0) val2 = 0;
        else val2 = num2[j] - '0';

        tempSum = val1 + val2 + overflow;

        if (tempSum >= 10) overflow = 1;
        else overflow = 0;

        if (digits >= (size - 1)) return NULL;

        result[digits] = (tempSum % 10) + '0';
        digits++;
        j--; i--;
    }

    if (digits == size) return NULL;

    result[digits] = '\0';
    reverseString(result);

    return result;
} 
