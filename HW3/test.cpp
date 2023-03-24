#include "countOOO.h"
#include <unordered_map>
#include <iostream>

std::vector<int> mergeSort(std::vector<int>, int &);
std::vector<int> merge(std::vector<int>, std::vector<int>, int &);
int countOOO(std::vector<std::string> rankedListA, std::vector<std::string> rankedListB);

int main()
{
    int num;
    std::vector<std::string> input1{"A", "B", "C", "D", "E", "F", "G"};
    std::vector<std::string> input2{"B", "D", "C", "A", "F", "G", "E"};

    num = countOOO(input1, input2);
    std::cout << num;
    return 0;
}


// countOOO computes the number of pairs of elements in rankedListA that are out of order in rankedListB
int countOOO(std::vector<std::string> rankedListA, std::vector<std::string> rankedListB)
{
    int listSize = rankedListA.size();
    int ooo = 0;

    std::unordered_map<std::string, int> reference;
    std::vector<int> placement(listSize, -1);

    for (int i = 0; i < listSize; i++)
    {
        reference[rankedListA[i]] = i;
    }

    for (int i = 0; i < listSize; i++)
    {
        placement[i] = reference[rankedListB[i]];
        //std::cout << placement[i];
    }

    //std::cout << std::endl;

    std::vector<int> resultvec = mergeSort(placement, ooo);

    

    return ooo; // don't forget to change this
}

std::vector<int> mergeSort(std::vector<int> in, int &ooo)
{
    if (in.size() <= 1)
    {
        return in;
    }
    else
    {
        int half = (in.size() / 2);
        std::vector<int> left(begin(in), (begin(in) + half));
        std::vector<int> right((begin(in) + half), end(in));

        //std::cout << left.size() << " " << right.size() << std::endl;
        std::cout << "L:";
        for(int i = 0; i < left.size(); i ++)
            std::cout << left[i];
        
        std::cout << " R:";
        for(int i = 0; i < right.size(); i ++)
            std::cout << right[i];

        std::cout << std::endl;

        std::vector<int> lSort = mergeSort(left, ooo);
        std::vector<int> rSort = mergeSort(right, ooo);

        return merge(lSort, rSort, ooo);
    }
}

std::vector<int> merge(std::vector<int> left, std::vector<int> right, int &ooo)
{
    int i = 0;
    int j = 0;
    int lSize = left.size();
    int rSize = right.size();
    std::vector<int> result;

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
        else if (left[i] < right[j])
        {
            result.push_back(left[i]);
            i++;
            
        }
        else
        {
            result.push_back(right[j]);
            ooo += (lSize - i);
            //std::cout << ooo;
            j++;
        }
    }

    std::cout << "result:";
    for(int i = 0; i < result.size(); i++)
    {
        std::cout << result[i];
    }
    std::cout << std::endl;
    return result;
}
