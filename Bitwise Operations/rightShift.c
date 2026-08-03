#include <stdio.h>

int logicalShift(int a, int n);
int main(void)
{
    int a, n;
    scanf("%d %d", &a, &n);

    int ans = logicalShift(a, n);
    printf("%d", ans);
    return 0;
}

int logicalShift(int a, int n)
{
    int mask = ~(((1 << 31) >> n) << 1);
    return (a >> n) & mask;
}