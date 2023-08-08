#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Use current time to generate a random seed
    srand(time(NULL));

    // Generate a random number between 1 and 100
    int number = rand() % 100 + 1;
    fprintf(stderr, "Random number: %d\n", number);

    int received;
    char line[100], response = ' ';

    // Keep reading numbers from the user and providing feedback
    while (response != '=') {
        fgets(line, 100, stdin);
        sscanf(line, "%d", &received);

        if (received < number)
            response = '>';
        else if (received > number)
            response = '<';
        else 
            response = '=';

        // Send the response to the user
        printf("%c\n", response);
        fflush(stdout);

        // Log the response
        fprintf(stderr, "%c\n", response);
    }

    fputs("Child: done.\n", stderr);
    return 0;
}
