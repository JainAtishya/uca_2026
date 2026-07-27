#include <stdio.h>

// This is a single-line comment

int main()
{
    int a = 10;
    int b = 20;

    printf("Hello // World\n");

    printf("This is not /* a comment */\n");

    char slash = '/';

    char quote = '\'';

    /*
        This is a
        multi-line comment.

        It should be removed.
    */

    int result = a / b;

    printf("Result = %d\n", result); // Print result

    char *str = "/* Still not a comment */";

    // Another comment

    return 0;
}