#include <stdio.h>

int sign(int a);
int main(void)
{
    int a;
    scanf("%d", &a);

    int ans = sign(a);
    printf("%d", ans);
    return 0;
}

int sign(int a)
{
    return (!!a) | (a >> 31);
}