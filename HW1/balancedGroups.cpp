#include "balancedGroups.h"
#include <algorithm>
#include <cmath>

Assignment balancedGroups(std::vector<int> const &birthdays)
{
    std::vector<int> a, b, days; //vectors to return and use for sorting
    days = birthdays; //copy birthday vector
    int aTotal = 0, bTotal = 0; //running sums for the birthdays of each group

    std::sort(days.begin(), days.end(), std::greater<int>()); //sort birthdays in descending order

    for(int i = 0; i < days.size(); i++) //move through the sorted birthday vector
    {
        if(bTotal < aTotal) //determine which group has the lowest current total and then add the next birthday to that group
        {
            b.push_back(days[i]);
            bTotal += days[i]; //add to running sum
        }
        else
        {
            a.push_back(days[i]);
            aTotal += days[i]; // add to running sum
        }
    }

    return Assignment(abs(aTotal - bTotal), a, b);
}