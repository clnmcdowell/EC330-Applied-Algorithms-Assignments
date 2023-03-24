#include "sortStudents.h"
// your includes here

std::vector<int> sortStudents(std::vector<int> days, std::vector<int> ids)
{
    std::vector<int> counter (ids.size(), 0);
    std::vector<int> nonIds;
    std::vector<int> result;

    for(int i = 0; i < days.size(); i++)
    {
        for(int j = 0; j < ids.size(); j++)
        {
            if(days[i] == ids[j])
            {
                counter[j]++;
                break;
            }
            else if(j == (ids.size() - 1))
            {
                nonIds.push_back(days[i]);
            }
        }
    }

    for(int i = 0; i < ids.size(); i++)
    {
        while(counter[i] != 0)
        {
            result.push_back(ids[i]);
            counter[i]--;
        }
    }

    for(int i = 0; i < nonIds.size(); i++)
    {
        result.push_back(nonIds[i]);
        for(int j = i + 1; j < nonIds.size(); j++)
        {
            if(nonIds[j] == nonIds[i])
            {
                result.push_back(nonIds[i]);
                nonIds.erase(begin(nonIds) + j);
                j--;
            }
        }
    }

    return result;
}