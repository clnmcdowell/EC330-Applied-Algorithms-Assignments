#include <vector>

std::vector<int> priorPerm(std::vector<int> P)
{
    int vecSize = P.size();
    std::vector<int> previous;
    int index = -1, swapNum;

    for (int i = (vecSize - 2); i >= 0; i--) // starting from the end of the vector find the place that was changed in this permutation
    {
        if (P[i] > P[i + 1])
        {
            index = i; //the index after which changes will be made for the previous permutation
            break;
        }
    }

    if (index != -1)
    {
        for (int i = (index + 1); i < vecSize; i++) //find the index of the largest number smaller than the value of P[index]
        {
            if (P[i] > P[index])
            {
                break;
            }
            else
            {
                swapNum = i;
            }
        }

        for (int i = 0; i < index; i++) //copy vector up to index
        {
            previous.push_back(P[i]);
        } 

        previous.push_back(P[swapNum]); //swap original index value with swapNum value

        for (int i = (vecSize - 1); i > index; i--) //copy the rest of the vector in reverse order
        {
            if(i == swapNum) //swap original swapNum value with index value
            {
                previous.push_back(P[index]);
            }
            else
            {
                previous.push_back(P[i]);
            }
        }
        return previous; // return previous permutation
    }

    return P;
}
