#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        char *p;
        int numMegabytes = strtol(argv[1], &p, 10);

        int arr[numMegabytes];
        int iter = 0;

        while(1)
        {
            arr[iter];
            iter = (iter + 1) % (numMegabytes - 1);
        }
    }

    return 0;
}
