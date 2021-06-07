#include <assert.h>
#include <signal.h>
#include <stdbool.h>  /* false */
#include <stdio.h>    /* perror */
#include <stdlib.h>   /* EXIT_SUCCESS, EXIT_FAILURE */
#include <sys/wait.h> /* wait, sleep */
#include <unistd.h>   /* fork, write */




void encode(pid_t pd, char *message)
{
    int i;

    i = 0;
    while (message[i])
    {

        i++;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        //error handeling
        return (1);
    }
    encode(argv[2]);
    kill(13046, SIGUSR1);
    usleep(100);
    return (0);
}