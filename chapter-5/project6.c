#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * Write a slight modification of program 5 using waitpid().
 * When would waitpid() be useful?
 */

int main(void)
{
    int status;
    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        return 1;
    } else if (rc == 0)
    {
        printf("Child Print\n");
    } else
    {
        int rc_wait = waitpid(rc, &status, 0);
        printf("Parent print\n");
    }

    return 0;
}
