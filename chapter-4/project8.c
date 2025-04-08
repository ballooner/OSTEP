#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * Write a program that forks() 2 children and connects the stdout of one
 * to the stdin of the other using pipe().
 */

int main(void)
{
    int fileDescriptors[2] = {3, 4};
    pipe(fileDescriptors);
    int child1;
    int child2;
    int status;

    if ((child1 = fork()))
    {
        close(fileDescriptors[0]);
        dup2(fileDescriptors[1], STDOUT_FILENO);
        close(fileDescriptors[1]);

        printf("%d", 5);
    } else if ((child2 = fork()))
    {
        int input;

        close(fileDescriptors[1]);
        dup2(fileDescriptors[0], STDIN_FILENO);
        close(fileDescriptors[0]);

        scanf("%d", &input);
        printf("Child1 num: %d.", input);

        putchar('\n');
    } else
    {
        close(fileDescriptors[0]);
        close(fileDescriptors[1]);
        waitpid(child1, &status, 0);
        waitpid(child2, &status, 0);
    }

    return 0;
}
