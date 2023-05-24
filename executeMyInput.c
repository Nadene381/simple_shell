#include "shell.h"
/**
* executeMyInput - function that executes a command
* @args: pointer passed in function
* @shellModes: variable passed in function
* @argv: pointer passed in function
* Return: 0
*/

void executeMyInput(char *args[], int shellModes, char *argv[])
{
int n;
pid_t myChild = fork();

switch (myChild)
{
case -1: /* Error handling - when fork() fails*/
perror("Error fork() failed");
exit(1);
case 0: /* This is the child process*/
execve(args[0], args, environ);
/* Check if shell is interactive or non-interactive mode*/
if (shellModes)
perror(argv[0]);
else
fprintf(stderr, "%s: %d: %s: not found\n", argv[0], getpid(), args[0]);
break;
default: /* This is the parent process*/
waitpid(myChild, &n, 0);
break;
}
}

