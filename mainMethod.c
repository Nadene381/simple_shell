#include "shell.h"

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
int shellMode, inputValue;
char *args[MAXIMUM__ARGS];
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
/* Check if shell is interactive or non-interactive mode*/
shellMode = isatty(STDIN_FILENO);
/* Call function to create the child process*/
executeMyInput(args, shellMode, argv);
} while (1);
free(userInput);
return (0);
}

