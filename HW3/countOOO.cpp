/*Explanation: This algorithm works by first adding each entry in list A to an unordered map and then using that map 
it goes through list B and creates a vector of integers corresponding to those "songs" placements in list A. Both
of these operations takes O(n) time as they loop through each entry in a size n vector. Then the algorithm uses two
functions to merge sort the integer vector and counts how many places it had to move entries from the right to the left
while merging, this gives you the OOO count. Merge sort takes O(nlogn) so the total complexity is O(n + n + nlogn)
which can be simplified to O(nlogn)*/

#include "countOOO.h"
#include <unordered_map>

std::vector<int> mergeSort(std::vector<int>, int &);
std::vector<int> merge(std::vector<int>, std::vector<int>, int &);

// countOOO computes the number of pairs of elements in rankedListA that are out of order in rankedListB
int countOOO(std::vector<std::string> rankedListA, std::vector<std::string> rankedListB)
{
    int listSize = rankedListA.size();
    int ooo = 0;

    std::unordered_map<std::string, int> reference;
    std::vector<int> placement(listSize, -1);

    for(int i = 0; i < listSize; i++)
    {
        reference[rankedListA[i]] = i; 
    }

    for(int i = 0; i < listSize; i++)
    {
        placement[i] = reference[rankedListB[i]];
    }
    
    mergeSort(placement, ooo);

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
            j++;
        }
    }

    return result;
}
