/*
hello.c asks for the user's name and then echoes the name with "Hello, <name>".
Input is expected to be typed into a terminal and end with a newline.
*/
#include <stdio.h>
#include <stdlib.h>

#define prompt "What's your name? "

int main()
{
    size_t bufsize = 0;
    char *buffer = NULL;
    ssize_t nread = 0;
    
    do
    {
        puts("\n" prompt);
        nread = getline(&buffer, &bufsize, stdin);
    } while (nread < 2);
    printf("Hello, %s\n", buffer);
    
    free(buffer);
    exit(EXIT_SUCCESS);
}
