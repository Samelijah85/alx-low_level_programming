#include <stdio.h>
#include <string.h>

char *infinite_add(char *n1, char *n2, char *r, int size_r) {
    int len1 = strlen(n1);
    int len2 = strlen(n2);
    int carry = 0;
    int max_len = (len1 > len2) ? len1 : len2;

    if (max_len + 1 > size_r) {
        return 0; // Result doesn't fit in the buffer
    }

    int i, j, k;
    for (i = len1 - 1, j = len2 - 1, k = 0; i >= 0 || j >= 0 || carry; i--, j--, k++) {
        int digit1 = (i >= 0) ? n1[i] - '0' : 0;
        int digit2 = (j >= 0) ? n2[j] - '0' : 0;
        int sum = digit1 + digit2 + carry;

        carry = sum / 10;
        r[k] = (sum % 10) + '0';
    }

    r[k] = '\0';

    // Reverse the result string
    int left = 0;
    int right = k - 1;
    while (left < right) {
        char temp = r[left];
        r[left] = r[right];
        r[right] = temp;
        left++;
        right--;
    }

    return r;
}

int main() {
    char n1[] = "12345678901234567890";
    char n2[] = "98765432109876543210";
    int size_r = 30;
    char result[size_r];

    char *sum = infinite_add(n1, n2, result, size_r);

    if (sum) {
        printf("Sum: %s\n", sum);
    } else {
        printf("Result does not fit in the buffer.\n");
    }

    return 0;
} 
