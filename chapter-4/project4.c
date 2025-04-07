#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

/**
 * Write a program that calls fork() and then calls some form of exec()
 * to run /bin/ls.
 * Why do you think there are so many forms of the exec call?
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
        char *myargs[2];
        myargs[0] = strdup("/bin/ls");
        myargs[1] = NULL;
        execvp(myargs[0], myargs);
    } else
    {
        int rc_wait = wait(NULL);
    }

    return 0;
}
