#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * Write a program that uses wait() in the child process. What happens?
 */

int main(void)
{
    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
    } else if (rc == 0)
    {
        int rc_wait = wait(NULL);
        printf("Child print\n");
    } else 
    {
        printf("Parent print\n");
    }

    return 0;
}
