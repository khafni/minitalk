#include <assert.h>
#include <signal.h>
#include <stdbool.h>  /* false */
#include <stdio.h>    /* perror */
#include <stdlib.h>   /* EXIT_SUCCESS, EXIT_FAILURE */
#include <sys/wait.h> /* wait, sleep */
#include <unistd.h>   /* fork, write */
#include <math.h>
#include "rstr.h"

double ft_pow(double base, double power);


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
        usleep(100);
        i++;
    }
}

void send_ending_metadata(pid_t pid)
{
    char *ending_metadata;
    int i;

    i = 0;
    ending_metadata = "!?466e^#7%6<&<%";
    while (ending_metadata[i])
        send_byte(pid, ending_metadata[i++]);
}


void send_starting_metadata(pid_t pid)
{
    char *starting_metadata;
    int i;
    char *pid_str;

    pid_str = ft_itoa(getpid());
    i = 0;
    while (pid_str[i])
        send_byte(pid, pid_str[i++]);
    i = 0;
    starting_metadata = "9?&b[f>%607";
    while (starting_metadata[i])
        send_byte(pid, starting_metadata[i++]);
}

/* void print_byte(char byte)
{
    int i;
    char c = 0;
    //int pow = 1;

    i = 0;
    while (i <= 7)
    {
        c += (((100 >> i) & 1) == 1) * pow(2, i);
        i++;
    }
} */

void encode(pid_t pid, char *message)
{
    int i;

    i = 0;
    send_starting_metadata(pid);
    while (message[i])
    {
        send_byte(pid, message[i]);
        i++;
    }
    send_ending_metadata(pid);
}


int main(int argc, char *argv[])
{
   
    encode(atoi(argv[1]), argv[2]);
    //kill(atoi(), SIGUSR1);
    //usleep(100);
    //send_byte(666, '0');
    //print_byte('0');
    //printf("%f", pow(3, 2));
    //write(1, "Ф", 3);
    char *s = "Ф";
    for (int i = 0; s[i]; i++)
        printf("%d\n", s[i]);
    return (0);
}