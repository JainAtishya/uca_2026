#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FILE_NAME "audit.log"

int main(int argc, char *argv[])
{
    int fd;

     if (argc == 3 && strcmp(argv[1], "--add") == 0)
    {
        fd = open(FILE_NAME, O_WRONLY | O_CREAT | O_APPEND, 0644);

        if (fd == -1)
        {
            perror("Error opening file");
            return 1;
        }

        write(fd, argv[2], strlen(argv[2]));
        write(fd, "\n", 1);

        close(fd);
    }

     else if (argc == 2 && strcmp(argv[1], "--view") == 0)
    {
        fd = open(FILE_NAME, O_RDONLY);

        if (fd == -1)
        {
            perror("Error opening file");
            return 1;
        }

        char ch;
        int line = 1;
        int startOfLine = 1;

        while (read(fd, &ch, 1) > 0)
        {
            if (startOfLine)
            {
                char lineStr[20];
                int len = sprintf(lineStr, "%d: ", line);
                write(STDOUT_FILENO, lineStr, len);
                startOfLine = 0;
            }

            write(STDOUT_FILENO, &ch, 1);

            if (ch == '\n')
            {
                line++;

                if (read(fd, &ch, 1) > 0)
                {
                    char lineStr[20];
                    int len = sprintf(lineStr, "%d: ", line);
                    write(STDOUT_FILENO, lineStr, len);
                    write(STDOUT_FILENO, &ch, 1);
                }
            }
        }

        close(fd);
    }

     else
    {
        printf("Usage:\n");
        printf("./auditlog --add \"message\"\n");
        printf("./auditlog --view\n");
    }

    return 0;
}
