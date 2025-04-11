#define _GNU_SOURCE

#include <stdio.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <unistd.h>
#include <sched.h>

/**
 * Program that measures the speed of a context switch by creating
 * a pipe between two processes on the same processor and measures how long
 * it takes to send a message between them.
 */

int main(void)
{
    //Set up pipe
    int fd[2];
    pipe(fd);

    //Set up CPU set
    cpu_set_t cpuSet;
    CPU_ZERO(&cpuSet);
    CPU_SET(0, &cpuSet);

    //Set timers up
    struct timeval time;
    int contextSwitchAverage = 0;

    if (fork() == 0)
    {
        sched_setaffinity(0, sizeof(cpuSet), &cpuSet);

        gettimeofday(&time, NULL);
        long long timeSent = (long long) time.tv_sec * 1000000 + time.tv_usec;
        printf("Time sent: %lld\n", timeSent);
        write(fd[1], &timeSent, sizeof(timeSent));
    } else 
    {
        sched_setaffinity(0, sizeof(cpuSet), &cpuSet);

        wait(NULL);

        long long timeSent;
        read(fd[0], &timeSent, sizeof(timeSent));
        gettimeofday(&time, NULL);
        long long timeReceived = (long long) time.tv_sec * 1000000 + time.tv_usec;
        printf("Time received: %lld\n", timeReceived);
        printf("Time taken: %lld\n", timeReceived - timeSent);
    }

    return 0;
}
