#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <vector>
#include <map>

int main (int argc, char** argv)
{
    size_t len = 16;
    char* line = (char*)malloc(len);
    size_t bytes;
    std::vector<int> list;
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
        list.push_back(number);
    }
    

    std::map<int, int> freq;
    int frequency = 0;
    freq[frequency]++;
    bool found = false;
    while(!found)
    {
        int i;
        for (i = 0; i < list.size(); i++)
        {
            frequency += list[i];
            if (freq[frequency] > 0)
            {
                found = true;
                break;
            }
            freq[frequency]++;
        }
    }

    printf("%d\n", frequency);

    return 0;
}
