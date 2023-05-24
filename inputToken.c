#include "shell.h"
/**
* myInputSplitToken - function that splits the input string
* @userInput: pointer passed in function
* @args: pointer passed in function
* Return: 0
*/
void myInputSplitToken(char *userInput, char *args[])
{
int myCount = 0;
char *newStringToken;
char *myDelimiter = " ";

newStringToken = strtok(userInput, myDelimiter);
do {
args[myCount] = newStringToken;
myCount++;
newStringToken = strtok(NULL, myDelimiter);
} while (newStringToken != NULL && myCount < MAXIMUM__ARGS - 1);

args[myCount] = NULL;
}

