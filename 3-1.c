#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main (int argc, char** argv)
{
    char fabric [1000][1000];
    int i, j;
    for (i = 0; i < 1000; i++)
    {
        for (j = 0; j < 1000; j++)
        {
            fabric[i][j] = '.';
        }
    }
    int overlap = 0;
    size_t len = 64;
    char* line = malloc(len);
    size_t bytes;
    while ((bytes = getline(&line, &len, stdin)) != -1)
    {
        int k = 0;
        while (line[k] != '@') { k++; }
        k += 2;
        int xcord = 0, ycord = 0;
        while (line[k] != ',')
        {
            xcord *= 10;
            xcord += line[k] - '0';
            k++;
        }
        k++;
        while (line[k] != ':')
        {
            ycord *= 10;
            ycord += line[k] - '0';
            k++;
        }
        k += 2;
        int w = 0, h = 0;
        while (line[k] != 'x')
        {
            w *= 10;
            w += line[k] - '0';
            k++;
        }
        k++;
        while (k != bytes-1)
        {
            h *= 10;
            h += line[k] - '0';
            k++;
        }
        printf("x: %d, y: %d, w: %d, h: %d\n", xcord, ycord, w, h);
        int xlim = xcord + w;
        if (xlim > 999) xlim = 999;
        int ylim = ycord + h;
        if (ylim > 999) ylim = 999;
        int xi, yi;
        for (yi = ycord; yi < ylim; yi++)
        {
            for (xi = xcord; xi < xlim; xi++)
            {
                if (fabric[yi][xi] == '.')
                {
                    fabric[yi][xi] = 'Z';
                }
                else if (fabric[yi][xi] == 'Z')
                {
                    fabric[yi][xi] = 'X';
                    overlap++;
                }
            }
        }
    }
    printf("%d\n", overlap);

    return 0;
}
