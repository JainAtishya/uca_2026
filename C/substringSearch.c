#include <stdio.h>

int find_substring(const char *haystack, const char *needle)
{
    for(int i = 0; haystack[i] != '\0'; i++)
    {
        int j = 0;

        while(needle[j] != '\0' && haystack[i + j] == needle[j])
        {
            j++;
        }

        if(needle[j] == '\0')
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    char haystack[] = "Embedded Systems";
    char needle[] = "bed";

    int index = find_substring(haystack, needle);

    if(index == -1)
    {
        printf("Substring not found.\n");
    }
    else
    {
        printf("Substring found at index %d\n", index);
    }

    return 0;
}