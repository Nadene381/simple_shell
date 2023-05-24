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
int shellMode;
ssize_t inputValue;
char *args[MAXIMUM__ARGS];
(void)argc;
do {
if (isatty(STDIN_FILENO)) /*Display prompt in interactive mode & get input*/
{
write(1, "$ ", 2 * sizeof(char));
fflush(stdout);
}
inputValue = getline(&userInput, &inputSize, stdin);
for (; inputValue == -1;) /*Error Handling - EOF condition/getline fails*/
{
if (feof(stdin))
{
free(userInput);
exit(EXIT_SUCCESS);
}
else
{
perror("Error");
free(userInput);
exit(EXIT_SUCCESS);
}
}
for (; userInput[inputValue - 1] == '\n';) /* Remove newline characters*/
{
userInput[inputValue - 1] = '\0';
}
myInputSplitToken(userInput, args);/*call function to split input string*/
shellMode = isatty(STDIN_FILENO); /* Check if shell is interactive mode*/
executeMyInput(args, shellMode, argv);/* Call funct to execute child process*/
myExit(userInput);  /*Call exit Function*/
} while (1);
free(userInput);
return (0);
}

