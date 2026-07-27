#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define NORMAL 0
#define STRING 1
#define CHARACTER 2
#define SINGLE_COMMENT 3
#define MULTI_COMMENT 4

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <file.c>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    int state = NORMAL;
    char ch;

    while (read(fd, &ch, 1) == 1)
    {
        switch (state)
        {
            case NORMAL:
            {
                if (ch == '"')
                {
                    putchar(ch);
                    state = STRING;
                }
                else if (ch == '\'')
                {
                    putchar(ch);
                    state = CHARACTER;
                }
                else if (ch == '/')
                {
                    char next;

                    if (read(fd, &next, 1) != 1)
                    {
                        putchar('/');
                        break;
                    }

                    if (next == '/')
                    {
                        state = SINGLE_COMMENT;
                    }
                    else if (next == '*')
                    {
                        state = MULTI_COMMENT;
                    }
                    else
                    {
                        putchar('/');
                        putchar(next);
                    }
                }
                else
                {
                    putchar(ch);
                }

                break;
            }

            case STRING:
            {
                putchar(ch);

                if (ch == '\\')
                {
                    if (read(fd, &ch, 1) != 1)
                        break;

                    putchar(ch);
                }
                else if (ch == '"')
                {
                    state = NORMAL;
                }

                break;
            }

            case CHARACTER:
            {
                putchar(ch);

                if (ch == '\\')
                {
                    if (read(fd, &ch, 1) != 1)
                        break;

                    putchar(ch);
                }
                else if (ch == '\'')
                {
                    state = NORMAL;
                }

                break;
            }

            case SINGLE_COMMENT:
            {
                if (ch == '\n')
                {
                    putchar('\n');
                    state = NORMAL;
                }

                break;
            }

            case MULTI_COMMENT:
            {
                if (ch == '*')
                {
                    char next;

                    if (read(fd, &next, 1) != 1)
                        break;

                    if (next == '/')
                    {
                        state = NORMAL;
                    }
                }

                break;
            }
        }
    }

    close(fd);

    return 0;
}