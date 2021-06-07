#define _XOPEN_SOURCE 700
#include <assert.h>
#include <signal.h>
#include <stdbool.h>  /* false */
#include <stdio.h>    /* perror */
#include <stdlib.h>   /* EXIT_SUCCESS, EXIT_FAILURE */
#include <sys/wait.h> /* wait, sleep */
#include <unistd.h>   /* fork, write */

void signal_handler1(int sig)
{
    printf("zero\n");
}

void signal_handler2(int sig)
{
    printf("one\n");
}

int main()
{
    pid_t pid;
    printf("%d\n", getpid());
    signal(SIGUSR1, signal_handler1);
    signal(SIGUSR2, signal_handler2);
    //while (1)
        pause ();
    return EXIT_SUCCESS;
}