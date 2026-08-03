#include <stdio.h>

int bang(int a);
int main(void)
{
    int a;
    scanf("%d", &a);

    int ans = bang(a);
    printf("%d", ans);
    return 0;
}

int bang(int a)
{
    return ((a | (~a + 1)) >> 31) + 1;
}