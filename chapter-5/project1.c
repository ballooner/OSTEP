#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * Write a program that calls fork(). 
 * Before calling fork have the main process access a variable and set
 * it's value to something. What value is the variable in the child?
 * What happens to the variable when the child and parent change its value?
 */

int main(void)
{
    int var = 100;
    int rc = fork();

    if (rc < 0)
    {
        //The fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0)
    {
        printf("Child PID (before change) var is: %d\n", var);
        var = 200;
        printf("Child PID (after change) var is: %d\n", var);
    } else 
    {
        printf("Parent (before change) var is: %d\n", var);
        var = 0;
        printf("Parent (after change) var is: %d\n", var);
    }

    return 0;
}
