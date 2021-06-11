# minitalk
a communication program in the form of a client and server that uses
inter-process communication via the SIGUSR1 and SIGUSR2 signals
to send simple string messages from the client program to the server program.
(works only on macos or bsd)
##how to use:
1. make
2. run the server by ./server
3. keep the server running and copy the pid that it printed
4. ./client (pid that the server printed) "message you want to send to the server"
5. the server will print the message
