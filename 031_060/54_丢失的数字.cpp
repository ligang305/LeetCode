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

int missingNumber1(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if(i != nums[i]) return i;
    }
    return nums.size();
}

int missingNumber(vector<int>& nums) {
    vector<int> vec(nums.size() + 1, -1);

    for (int i = 0; i < nums.size(); i++)
    {
        vec[nums[i]] = nums[i];
    }
    for (int i = 0; i < vec.size(); i++)
    {
        if(vec[i] == -1) return i;
    }
    
    return nums.size();
}

int main()
{
    vector<int> nums = {0,2};
    cout << missingNumber(nums) << endl;
    return 0;
}