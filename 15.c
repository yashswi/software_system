
#include <stdio.h>
#include <stdlib.h>

extern char **ev;

int main() {
    
    for (int i = 0; ev[i] != NULL; i++)
    {
        printf("%s\n", ev[i]);
    }
//iterating through the null pointer
    return EXIT_SUCCESS;
}
