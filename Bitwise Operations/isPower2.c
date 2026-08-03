#include <stdio.h>

int isPower2(int a);
int main(void)
{
    int a;
    scanf("%d", &a);

    int ans = isPower2(a);
    printf("%d", ans);
    return 0;
}

int isPower2(int x)
{
    return x > 0 && !(x & (x - 1));
}