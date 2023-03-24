#include <string>
#include <vector>
#include "sorta.h"

std::vector<std::vector<int>> mergeSort(std::vector<std::vector<int>>);
std::vector<std::vector<int>> merge(std::vector<std::vector<int>>, std::vector<std::vector<int>>);

std::string sortByFreq(std::string s) {
    std::vector<std::vector<int>> counts;
    std::string values = "0123456789abcdefghijklmnopqrstuvwxyz";
    std::string result;

    for(int i = 0; i < 36; i++)
    {
        counts.push_back({0, int(values[i])});
    }

    for(int i = 0; i < s.size(); i++)
    {
        switch(s[i]){
            case '0':
                counts[0][0]++;
                break;
            case '1':
                counts[1][0]++;
                break;
            case '2':
                counts[2][0]++;
                break;
            case '3':
                counts[3][0]++;
                break;
            case '4':
                counts[4][0]++;
                break;
            case '5':
                counts[5][0]++;
                break;
            case '6':
                counts[6][0]++;
                break;
            case '7':
                counts[7][0]++;
                break;
            case '8':
                counts[8][0]++;
                break;
            case '9':
                counts[9][0]++;
                break;
            case 'a':
                counts[10][0]++;
                break;
            case 'b':
                counts[11][0]++;
                break;
            case 'c':
                counts[12][0]++;
                break;
            case 'd':
                counts[13][0]++;
                break;
            case 'e':
                counts[14][0]++;
                break;
            case 'f':
                counts[15][0]++;
                break;
            case 'g':
                counts[16][0]++;
                break;
            case 'h':
                counts[17][0]++;
                break;
            case 'i':
                counts[18][0]++;
                break;
            case 'j':
                counts[19][0]++;
                break;
            case 'k':
                counts[20][0]++;
                break;
            case 'l':
                counts[21][0]++;
                break;
            case 'm':
                counts[22][0]++;
                break;
            case 'n':
                counts[23][0]++;
                break;
            case 'o':
                counts[24][0]++;
                break;
            case 'p':
                counts[25][0]++;
                break;
            case 'q':
                counts[26][0]++;
                break;
            case 'r':
                counts[27][0]++;
                break;
            case 's':
                counts[28][0]++;
                break;
            case 't':
                counts[29][0]++;
                break;
            case 'u':
                counts[30][0]++;
                break;
            case 'v':
                counts[31][0]++;
                break;
            case 'w':
                counts[32][0]++;
                break;
            case 'x':
                counts[33][0]++;
                break;
            case 'y':
                counts[34][0]++;
                break;
            case 'z':
                counts[35][0]++;
                break;
        }

    }

    counts = mergeSort(counts);

    for(int i = 0; i < 36; i++)
    {
        for(int j = 0; j < counts[i][0]; j++)
        {
            result.push_back(char(counts[i][1]));
        }
    }

    return result; // you will need to change this
}

std::vector<std::vector<int>> mergeSort(std::vector<std::vector<int>> in) //I wrote this merge sort algorithm for HW3 and made some modifications to work with this problem.
{
    if (in.size() <= 1)
    {
        return in;
    }
    else
    {
        int half = (in.size() / 2);
        std::vector<std::vector<int>> left(begin(in), (begin(in) + half));
        std::vector<std::vector<int>> right((begin(in) + half), end(in));

        std::vector<std::vector<int>> lSort = mergeSort(left);
        std::vector<std::vector<int>> rSort = mergeSort(right);

        return merge(lSort, rSort);
    }
}

std::vector<std::vector<int>> merge(std::vector<std::vector<int>> left, std::vector<std::vector<int>> right)
{
    int i = 0;
    int j = 0;
    int lSize = left.size();
    int rSize = right.size();
    std::vector<std::vector<int>> result;

    while ((i != lSize) || (j != rSize))
    {
        if (i == lSize)
        {
            result.push_back(right[j]);
            j++;
        }
        else if (j == rSize)
        {
            result.push_back(left[i]);
            i++;
        }
        else if (left[i][0] > right[j][0])
        {
            result.push_back(right[j]);
            j++;
        }
        else
        {
            result.push_back(left[i]);
            i++;
        }
    }

    return result;
}