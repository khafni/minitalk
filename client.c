#include <assert.h>
#include <signal.h>
#include <stdbool.h>  /* false */
#include <stdio.h>    /* perror */
#include <stdlib.h>   /* EXIT_SUCCESS, EXIT_FAILURE */
#include <sys/wait.h> /* wait, sleep */
#include <unistd.h>   /* fork, write */


void send_byte(pid_t pid, char byte)
{
    int i;

    i = 0;
    while (i <= 7)
    {
        if ((byte >> i) & 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        i++;
    }
}

void encode(pid_t pid, char *message)
{
    int i;

    i = 0;
    while (message[i])
    {
        //printf("%c", message[i]);
        send_byte(pid, message[i]);
        i++;
    }
}

int main(int argc, char *argv[])
{
   /*  if (argc != 3)
    {
        //error handeling
        return (1);
    } */
    encode(atoi(argv[1]), argv[2]);
    //kill(1773577, SIGUSR1);
    sleep(1);
    //send_byte(666, '0');
    return (0);
}