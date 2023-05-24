#include "shell.h"
/**
 *myExit - function that exit shell session
 *@userInput: pointer passed in function
 *Return: 0
 */
void myExit(char *userInput)
{
if (strcmp(userInput, "exit\n") == 0)
exit(EXIT_FAILURE);
}

