#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

/**
 * This program is used to measure how long a system call takes.
 */

int main(void)
{
    struct timeval tv;
    long long timeDifference = 0;
    double average = 0;

    for (int i = 0; i < 1000; i++)
    {
        //Get time before read
        gettimeofday(&tv, NULL);
        timeDifference = (long long) tv.tv_sec * 1000000 + tv.tv_usec;

        //Perform the read
        read(1, NULL, 0);
        
        //Get time after read
        gettimeofday(&tv, NULL);
        timeDifference = ((long long) tv.tv_sec * 1000000 + tv.tv_usec) - 
                          timeDifference;

        average += timeDifference;
        timeDifference = 0;
    }

    printf("%f microseconds\n", average / 1000);

    return 0;
}
