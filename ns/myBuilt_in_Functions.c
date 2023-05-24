#include "shell.h"
/**
 *myExit - function that exit shell session
 *Return: 0
 */
void myExit()
{
exit(EXIT_SUCCESS);
}

void myEnv() {
    int i = 0;
    while (environ[i] != NULL)
    {
        printf("%s\n", environ[i]);
        i++;
    }
}
