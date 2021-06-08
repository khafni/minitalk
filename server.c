#define _XOPEN_SOURCE 700
#include <assert.h>
#include <signal.h>
#include <stdbool.h>  /* false */
#include <stdio.h>    /* perror */
#include <stdlib.h>   /* EXIT_SUCCESS, EXIT_FAILURE */
#include <sys/wait.h> /* wait, sleep */
#include <unistd.h>   /* fork, write */
#include <math.h>
#include "rstr.h"


void signal_handler1(int sig)
{
    printf("zero\n");
}

void signal_handler2(int sig)
{
    printf("one\n");
}

int get_index_of_stm(t_rstr rs)
{
    char *haystack;
    char *needle;
    int indx;

    haystack = rstr_to_cstr(rs);
    needle = "9?&b[f>%607";
    indx = strstr_modified(haystack, needle);
    rstr_destroy(haystack);
    return (indx);
}
char *get_client_pid(t_rstr rs)
{
    int indx;

    indx = get_index_of_stm(rs);
}

/*
** bitshifting to the left is equivalent to multiplying by 2
*/
void signal_handler(int signal)
{
    static int i;
    static unsigned char byte;
    static t_rstr rs = NULL;

    if (!rs)
        rs = rstr_create(0);
    byte += ((signal == SIGUSR1) << i);
    i++;
    if (i > 7)
    {
        i = 0;
        rstr_add(rs, byte);
        if (!is_str_at_rstr_end(rs, "!?466e^#7%6<&<%"))
        {
            rs->len -= 15;
            write(1, rstr_to_cstr(rs), rs->len);
            write(1, "\n", 1);
            rstr_clear(rs);
        }
        //write(1, &byte, 1);
        byte = 0;
        return ;
    }
}


int main()
{
    pid_t pid;
    printf("%d\n", getpid());
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);
    // signal(SIGUSR2, store_bits);
    while (1)
        pause ();
    //t_rstr rs = cstr_to_rstr("fuck80d whatever80d<@>6!c&f#3ce?}f4f57%6<&<%");
    //printf("%d\n", is_str_at_rstr_end(rs, "80d<@>6!c&f#3ce?}f4f57%6<&<%"));
    return EXIT_SUCCESS;
}