
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_error(void)
{
    printf("Error\n");
    exit(98);
}

void print_product(char *product)
{
    int i = 0;

    while (product[i] == '0' && product[i + 1] != '\0')
        i++;

    printf("%s\n", &product[i]);
}

void multiply(char *num1, int len1, char *num2, int len2)
{
    int i, j, k, n;
    int *result;
    char *product;

    result = calloc(len1 + len2, sizeof(int));
    if (result == NULL)
        print_error();

    product = calloc(len1 + len2 + 1, sizeof(char));
    if (product == NULL)
        print_error();

    for (i = len1 - 1; i >= 0; i--)
    {
        n = 0;
        for (j = len2 - 1; j >= 0; j--)
        {
            k = i + j + 1;
            n += (num1[i] - '0') * (num2[j] - '0') + result[k];
            result[k] = n % 10;
            n /= 10;
        }
        result[i + j + 1] = n;
    }

    for (i = 0, j = 0; i < len1 + len2; i++)
    {
        if (result[i] != 0 || j)
            product[j++] = result[i] + '0';
    }
    product[j] = '\0';

    print_product(product);

    free(result);
    free(product);
}

int main(int argc, char *argv[])
{
    char *num1, *num2;
    int len1, len2, i;

    if (argc != 3)
        print_error();

    for (i = 1; i < 3; i++)
    {
        for (int j = 0; argv[i][j]; j++)
        {
            if (argv[i][j] < '0' || argv[i][j] > '9')
                print_error();
        }
    }

    num1 = argv[1];
    len1 = strlen(num1);
    num2 = argv[2];
    len2 = strlen(num2);

    multiply(num1, len1, num2, len2);

    return 0;
}