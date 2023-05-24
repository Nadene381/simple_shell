#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAXIMUM__ARGS 64
void myInputSplitToken(char *userInput, char *args[]);

#endif   
