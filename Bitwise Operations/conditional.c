#include <stdio.h>

int conditional(int x, int y, int z)
{
    int mask = ~(!x) + 1;
    return (~mask & y) | (mask & z);
}
int main(void)
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int ans = conditional(a, b, c);
    printf("%d", ans);
    return 0;
}