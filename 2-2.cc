#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

int hammingDist(std::string a, std::string b)
{
    if (a.length() != b.length()) return -1;
    int i;
    int count = 0;
    for (i = 0; i < a.length(); i++)
    {
        if (a[i] != b[i])
            count++;
    }
    return count;
}

int main (int argc, char** argv)
{
    std::vector<std::string> ids;
    std::string line;
    while (std::cin >> line)
    {
        ids.push_back(line);
    }
    int found = 0;
    int i, j;
    for (i = 0; i < ids.size()-1; i++)
    {
        for (j = i+1; j < ids.size(); j++)
        {
            if (hammingDist(ids[i], ids[j]) == 1)
            {
                found = 1;
                break;
            }
        }
        if (found) break;
    }
    
    for (int k = 0; k < ids[i].length(); k++)
    {
        if (ids[i][k] == ids[j][k])
            putchar(ids[i][k]);
    }
    putchar('\n');

    return 0;
}
