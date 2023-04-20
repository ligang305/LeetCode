#include <iostream>
#include "stack"
#include "unistd.h"
#include "vector"
#include "queue"
#include "map"
#include "unordered_set"
#include "unordered_map"
#include <math.h>
#include "algorithm"
#include <list>
using namespace std;

bool isUgly(int n)
{
    if (n < 1)
        return false;
    vector<int> nums = {2, 3, 5};
    for (int i = 0; i < 3; i++)
    {
        if (n % nums[i] == 0)
        {
            while (n % nums[i] == 0)
            {
                n /= nums[i];
            }
        }
    }
    return n == 1;
}

int main()
{
    cout << isUgly(75) << endl;
    cout << "很快啊." << endl;
    return 0;
}