/*
hello.c asks for the user's name and then echoes the name with "Hello, <name>"
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int index = 0;
    size_t bufsize = 32;
    char *buffer = malloc(bufsize * sizeof *buffer);    
    ssize_t nbytes = 0;
    /* Check that buffer is OK */
    if (buffer == NULL) {
        puts("Error allocating memory");
        abort();
    }
    
    /* Get user's name  */
    do {
        if (nbytes == 1) { /* implies EOF was entered */
            puts("");
            puts("EOF? Use ctrl-c to abort.");
        }
        if (buffer[0] == '\n')
            puts("You don't have a name? Try again.");
        printf("What is your name? ");
    } while((nbytes = getline(&buffer, &bufsize, stdin) == -1)
        || buffer[0] == '\n');
    
    /* Remove newline from buffer */
    while(buffer[++index] != '\n');
    buffer[index] = '\0';
    
    /* Display message to the user */
    printf("Hello, %s\n", buffer);
    
    /* Clean up */
    free(buffer);
    
    return 0;
}
