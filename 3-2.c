#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct entry
{
    int xc;
    int yc;
    int xlimit;
    int ylimit;
};

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
    struct entry info[1500];
    int overlap = 0;
    size_t len = 64;
    char* line = malloc(len);
    size_t bytes;
    int ei = 0;
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
        int xlim = xcord + w;
        if (xlim > 999) xlim = 999;
        int ylim = ycord + h;
        if (ylim > 999) ylim = 999;
        info[ei].xc = xcord;
        info[ei].yc = ycord;
        info[ei].xlimit = xlim;
        info[ei].ylimit = ylim;

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
        ei++;
    }
    int solo;
    int ent;
    int xi, yi;
    for (ent = 0; ent < ei; ent++)
    {
        for (yi = info[ent].yc; yi < info[ent].ylimit; yi++)
        {
            for (xi = info[ent].xc; xi < info[ent].xlimit; xi++)
            {
                if (fabric[yi][xi] != 'Z') goto notfound;
            }
        }
        solo = ent+1;
        break;
notfound:
        continue;
    }
    printf("%d\n", solo);

    return 0;
}
