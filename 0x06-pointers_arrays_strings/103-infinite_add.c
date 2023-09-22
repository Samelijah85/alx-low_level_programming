#include <stdio.h>

/**
 * infinite_add - add two numbers stored as strings
 * @n1: first number as a string
 * @n2: second number as a string
 * @r: buffer to store the result
 * @size_r: size of the buffer
 * Return: pointer to the result in the buffer, or 0 if result cannot fit
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int len1 = 0, len2 = 0, carry = 0, sum = 0;
    int i, j;

    while (n1[len1] != '\0')
        len1++;
    while (n2[len2] != '\0')
        len2++;

    if (len1 + 1 > size_r || len2 + 1 > size_r)
        return (0);

    r[size_r] = '\0'; // Null-terminate the result string
    len1--;
    len2--;

    for (i = size_r - 1; len1 >= 0 || len2 >= 0 || carry; i--)
    {
        sum = carry;
        if (len1 >= 0)
            sum += n1[len1] - '0';
        if (len2 >= 0)
            sum += n2[len2] - '0';

        carry = sum / 10;
        r[i] = (sum % 10) + '0';

        if (i == 0 && (len1 > 0 || len2 > 0 || carry))
            return (0);

        if (len1 >= 0)
            len1--;
        if (len2 >= 0)
            len2--;
    }

    return (r + i + 1); // Return a pointer to the beginning of the result string
}

int main(void)
{
    char *n = "1234567892434574367823574575678477685785645685876876774586734734563456453743756756784458";
    char *m = "9034790663470697234682914569346259634958693246597324659762347956349265983465962349569346";
    char r[100];
    char r2[10];
    char r3[11];
    char *res;

    res = infinite_add(n, m, r, 100);
    if (res == 0)
    {
        printf("Error\n");
    }
    else
    {
        printf("%s + %s = %s\n", n, m, res);
    }

    // Additional test cases
    // ...

    return (0);
} 
