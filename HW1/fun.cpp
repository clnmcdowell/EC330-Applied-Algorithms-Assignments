#include "fun.h"

unsigned int fun(unsigned int x, unsigned int y)
{
    if(y == 0)
        return (x + 1); // satisfies equations 1 and 3
    
    return 2;
}

/*Explanation: The base cases for this function are equations 1 and 3
and occur when called with y = 0. If initially called with y != 0 equation 2
[fun(1, y - 1)] may be called which can then call a base case if y = 1, ultimately 
returning 2, or equation 4 [fun(x - 1, fun(x - 1, y -1))] will be called. Because
it the right side of equation 4 is a recursive call and it is impossible for a base
case to return 0 equation 4 will never call a base case. Rather it will recur until
the left side is reduced to 0 and call equation 2 at which point equation 2 will either
return 2 or call equation 4 again. This will repeat until equation 2 returns 2 so unless
fun is initially called with y = 0 it will return 2*/