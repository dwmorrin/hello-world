#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t bufsize = 32;
    char *buffer = malloc(bufsize * sizeof *buffer);
    int index = 0;
    if (buffer == NULL) {
        puts("Error allocating memory");
        abort();
    }
    
    do {
        if (buffer[0] == '\n')
            printf("You don't have a name? Try again.\n");
        printf("What is your name? ");
    } while(!getline(&buffer, &bufsize, stdin) || buffer[0] == '\n');
    
    while(buffer[++index] != '\n');
    buffer[index] = '\0';
    printf("Hello, %s\n", buffer);
    
    return 0;
}
