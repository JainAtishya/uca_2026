#include <stdio.h>

void url_encode(char str[], int true_length)
{
    int spaces = 0;

    for (int i = 0; i < true_length; i++)
    {
        if (str[i] == ' ')
            spaces++;
    }

    int newIndex = true_length + (spaces * 2);

    str[newIndex] = '\0';

    for (int i = true_length - 1; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            str[newIndex - 1] = '0';
            str[newIndex - 2] = '2';
            str[newIndex - 3] = '%';
            newIndex -= 3;
        }
        else
        {
            str[newIndex - 1] = str[i];
            newIndex--;
        }
    }
}

int main()
{
    char str[30] = "Hello World";

    url_encode(str, 11);

    printf("%s", str);

    return 0;
}