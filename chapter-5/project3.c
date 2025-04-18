#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * Write another program using fork(). The child process should print "hello";
 * the parent process should print "goodbye". 
 * You should try to ensure that the child process always prints first;
 * can you do this without calling wait() in the parent?
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
        printf("Hello\n");
    } else 
    {
        int rc_wait = wait(NULL);
        printf("Goodbye\n");
    }

    return 0;
}
