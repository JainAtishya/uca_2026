#include <stdio.h>

int fitBits(int a, int n);
int main(void)
{
    int a, n;
    scanf("%d %d", &a, &n);

    int ans = fitBits(a, n);
    printf("%d", ans);
    return 0;
}

int fitBits(int x, int n)
{
    int shift = 32 + (~n + 1);
    return !(((x << shift) >> shift) ^ x);
}