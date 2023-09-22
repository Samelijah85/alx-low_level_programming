#include <stdio.h>
#include <string.h>

/**
 * rev_string - reverse array
 * @n: array to be reversed
 * Return: void
 */
void rev_string(char *n)
{
  int i, j;
  char temp;
  
  i = 0;
  j = strlen(n) - 1;
  
  while (i < j)
  {
    temp = n[i];
    n[i] = n[j];
    n[j] = temp;
    i++;
    j--;
  }
}

/**
 * infinite_add - add two numbers together
 * @n1: first number as a string
 * @n2: second number as a string
 * @r: buffer to store the result
 * @size_r: size of the buffer
 * Return: pointer to the result
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
  int i, j, k;
  int len1, len2, carry, sum;
  
  len1 = strlen(n1);
  len2 = strlen(n2);
  
  if (len1 >= size_r || len2 >= size_r)
    return 0;
  
  i = len1 - 1;
  j = len2 - 1;
  k = 0;
  carry = 0;
  
  while (i >= 0 || j >= 0 || carry > 0)
  {
    sum = carry;
    
    if (i >= 0)
      sum += n1[i] - '0';
    
    if (j >= 0)
      sum += n2[j] - '0';
    
    r[k] = sum % 10 + '0';
    carry = sum / 10;
    
    i--;
    j--;
    k++;
  }
  
  r[k] = '\0';
  rev_string(r);
  
  return r;
}

int main()
{
  char num1[] = "123";
  char num2[] = "456";
  char result[100];
  
  printf("Adding %s and %s\n", num1, num2);
  
  infinite_add(num1, num2, result, sizeof(result));
  
  printf("Result: %s\n", result);
  
  return 0;
} 
