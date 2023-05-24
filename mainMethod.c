#include "shell.h"
/**
* myInputSplitToken - function that splits the input string
* @userInput: pointer passed in function
* @args: pointer passed in function
* Return: 0
*/
void myInputSplitToken(char *userInput, char *args[])
{
int myCounter = 0;
char *newStringToken;
char *myDelimiter = " ";

newStringToken = strtok(userInput, myDelimiter);
do {
args[myCounter] = newStringToken;
myCounter++;
newStringToken = strtok(NULL, myDelimiter);
} while (newStringToken != NULL && myCounter < MAXIMUM__ARGS - 1);

args[myCounter] = NULL;
}
/**
* main - check the code
* @argc: variable passed in function
* @argv: pointer passes in function
* Return: 0
*/

int main(int argc, char *argv[])
{
char *userInput = NULL;
size_t inputSize = 0;
int inputValue;
int n, shellMode;
char *args[MAXIMUM__ARGS];
pid_t myChild;
(void)argc;
do {
/*Display prompt & get input using getline*/
write(1, "$ ", 2);
fflush(stdout);
inputValue = getline(&userInput, &inputSize, stdin);
/* Remove newline characters*/
for (; userInput[inputValue - 1] == '\n';)
{
userInput[inputValue - 1] = '\0';
}
/*Error Handling - EOF condition/getline fails*/
if (inputValue == -1)
{
return (-1);
exit(EXIT_FAILURE);
}
/*call function to split input string into individual tokens*/
myInputSplitToken(userInput, args);
/*Create a child-Process*/
myChild = fork();
switch (myChild)
{
case -1: /*Error handling - when fork() fails*/
perror("Error fork() failed");
exit(1);
case 0: /* This is the child process*/
execve(args[0], args, NULL);
/*Check if shell is interactive or non interactive mode*/
shellMode = isatty(STDIN_FILENO);
if (shellMode != 0)
{
perror(argv[0]);
}
else
{
fprintf(stderr, "%s: %d: %s: not found\n", argv[0], getpid(), args[0]);
}
break;
default: /*This is the parent process*/
waitpid(myChild, &n, 0);
break;
}
} while (1);
free(userInput);
return (0);
}

