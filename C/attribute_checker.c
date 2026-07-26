#include <stdio.h>
#include <sys/stat.h>
#include <time.h>


void printFileType(mode_t mode)
{
    if(S_ISREG(mode))
    {
        printf("File Type:            Regular File\n");
    }
    else if(S_ISDIR(mode))
    {
        printf("File Type:            Directory\n");
    }
    else if(S_ISLNK(mode))
    {
        printf("File Type:            Symbolic Link\n");
    }
    else if(S_ISCHR(mode))
    {
        printf("File Type:            Character Device\n");
    }
    else if(S_ISBLK(mode))
    {
        printf("File Type:            Block Device\n");
    }
    else if(S_ISFIFO(mode))
    {
        printf("File Type:            FIFO/Pipe\n");
    }
    else if(S_ISSOCK(mode))
    {
        printf("File Type:            Socket\n");
    }
    else
    {
        printf("File Type:            Unknown\n");
    }
}


int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    struct stat info;

    if(stat(argv[1], &info) == -1)
    {
        perror("stat");
        return 1;
    }

    printf("=== File Attributes for: %s ===\n\n", argv[1]);

    printFileType(info.st_mode);

    printf("Permissions:          %04o\n", info.st_mode & 0777);

    printf("File Size:            %ld bytes\n", info.st_size);

    printf("Hard Links Count:     %ld\n", info.st_nlink);

    printf("Owner (UID):          %d\n", info.st_uid);

    printf("Group (GID):          %d\n", info.st_gid);

    printf("Last Access Time:     %s", ctime(&info.st_atime));

    printf("Last Modification:    %s", ctime(&info.st_mtime));

    printf("Status Change Time:   %s", ctime(&info.st_ctime));

    return 0;
}