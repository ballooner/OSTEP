#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * Write a program that creates a child process, and then in the child
 * closes standard output (STDOUT_FILENO). What happens if the child
 * calls printf?
 */

int main(void)
{
    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        return 1;
    } else if (rc == 0)
    {
        close(STDOUT_FILENO);
        printf("Child print\n");
    } else {
        int rc_wait = wait(NULL);
        printf("Parent print\n");
    }

    return 0;
}
