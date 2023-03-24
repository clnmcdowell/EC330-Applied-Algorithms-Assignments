#include <iostream>

using namespace std;

int foo(int x)
{
    if (x == 1)
        return 1;
    else
        return 2 * foo(int(x / 2));
}

int fun(int x, int y)
{
    if (x == 0 && y == 0)
    {
        return 1;
    }
    else if (x == 0 && y != 0)
    {
        return fun(1, (y - 1));
    }
    else if (x != 0 && y == 0)
    {
        return (x + 1);
    }
    else
    {
        return fun((x - 1), fun((x - 1), (y - 1)));
    }
}

int fun2(int x, int y)
{
    switch (y)
    {
        case 0:
            return (x + 1); // satisfies the case where x is also 0 and when its not
        default:
            return 2;
    }
}

int	main()
{
    int n = 15;
    int sum = 1;
    for (int i = 2; i < n; i++)
    {
        sum = sum + (1 << i);
    }

    cout << sum;
    return 0;
}