#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main (int argc, char** argv)
{
    int frequency = 0;
    size_t len = 16;
    char* line = malloc(len);
    size_t bytes;
    while ((bytes = getline(&line, &len, stdin)) != -1)
    {
        int i = 1;
        int number = 0;
        while (isdigit(line[i]))
        {
            number *= 10;
            number += line[i] - '0';
            i++;
        }
        if (line[0] == '-')
        {
            number *= -1;
        }
        frequency += number;
    }
    printf("%d\n", frequency);

    return 0;
}
