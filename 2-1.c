#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main (int argc, char** argv)
{
    int twos = 0;
    int threes = 0;
    size_t len = 32;
    char* line = malloc(len);
    size_t bytes;
    while ((bytes = getline(&line, &len, stdin)) != -1)
    {
        int twoflag = 0;
        int threeflag = 0;
        int letters[26] = {0};
        int i = 0;
        while (islower(line[i]))
        {
            int ind = line[i] - 'a';
            letters[ind]++;
            i++;
        }
        for (i = 0; i < 26; i++)
        {
            if (letters[i] == 2)
            {
                twoflag = 1;
            }
            if (letters[i] == 3)
            {
                threeflag = 1;
            }
        }
        if (twoflag) twos++;
        if (threeflag) threes++;
    }
    printf("%d\n", twos * threes);

    return 0;
}
