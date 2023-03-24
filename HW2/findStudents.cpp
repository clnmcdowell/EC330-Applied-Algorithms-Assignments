#include <vector>

std::vector<int> findStudents(std::vector<int> id)
{
    std::vector<int> mods(330, -1); //stores the modulos of ids that have already been checked
    std::vector<int> returnVec;
    int minMod = 330, index1, index2, currentMod, currentIndex;
    int vecSize = id.size();

    mods[id[0] % 330] = 0; //store mod of first value in mods vector

    for(int i = 1; i < vecSize; i++) //loops through the id vector
    {
        currentMod = id[i] % 330; //mod of current id
        if(currentMod == 0)
        {
            currentIndex = 0;
        }
        else
        {
            currentIndex = 330 - currentMod; //start at the index where the sum of those mods will be 0
        }

        for(int j = 0; j < minMod; j++) //loop through the mods vector at most minMod times
        {
            if(mods[currentIndex] != -1) //looping for any stored indexes that would result in a new minimum mod
            {
                index1 = i; //store new indexes for the minimum mod 
                index2 = mods[currentIndex];
                minMod = (currentIndex + currentMod) % 330; //store new min mod value
                break; //stop checking, any further indexes will result in a sum with a higher mod
            }
            else
            {
                if(currentIndex == 329)
                {
                    currentIndex = 0; //go to start of mod vector if you reached the end
                }
                else
                {
                    currentIndex++; //increment index
                }
            }
        }

        if(minMod == 0) //if a sum is found with a mod of 0 there is no point in checking more
        {
            break;
        }
        else
        {
            mods[currentMod] = i; //store the mod of the current id in the mods vector for future checking
        } 
    }

    returnVec.push_back(id[index1]); //generate return vector with minimum mod indexes
    returnVec.push_back(id[index2]);

    return returnVec;
}

/*Notes on time complexity: this algorithm works by checking the values stored in the size 330 mods vector once for
each value of the input id vector. This means that in the worst case scenario it will perform these checks 330n times
where n is the size of the input vector. Realistically that will probably never happen because it is optimized to
perform the minimum number of checks necessary for each value, which will decrease as smaller mod values are found
and will stop checking entirely if it finds two numbers with a sum whose mod is 0. Regardless, the asymptotic complexity
is, as I previously mentioned, linear O(330n) which faster than the O(n^2) required for this assignment.*/