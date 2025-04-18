#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * Write a program that opens a file (with open()) and then calls fork().
 * Can both the child and parent access the file descriptor returned by open()?
 * What happens when they try to write to the file at the same time?
 */

int main(void)
{
    int file = open("../testfile.txt", O_RDWR);
    if (file < 0)
    {
        fprintf(stderr, "file open failed");
        return 1;
    }

    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        return 1;
    } else if (rc == 0)
    {
        printf("Child file descriptor: %d\n", file);
        char c = 'b';
        write(file, &c, 1);
        printf("Child file wrote: 'b'\n");
    } else 
    {
        printf("Parent file descriptor: %d\n", file);
        char c = 'a';
        write(file, &c, 1);
        printf("Parent wrote: 'a'\n");
    }

    return 0;
}
