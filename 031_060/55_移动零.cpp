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

// 输入: nums = [0,1,0,3,12]
// 输出: [1,3,12,0,0]
void moveZeroes(vector<int>& nums) {
    int index = 0;
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        if(nums[i] != 0){
            swap(nums[index], nums[i]);
            index++;
        }
    }
    
}

void moveZeroes2(vector<int>& nums) {
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        if(nums[i] != 0) continue;
        //找到下一个不为零的数 交换
        int j = i+1;
        while (j < size-1 && nums[j] == 0)
        {
            j++;
        }
        if(j < size) swap(nums[i], nums[j]);
    }
    
}

void moveZeroes1(vector<int>& nums) {
    int size = nums.size();
    for (int i = size - 1; i >= 0; i--)
    {
        if(nums[i] != 0) continue;
        for (int j = i; j < size-1; j++)
        {
            if(nums[j+1] == 0) continue;
            int tmp = nums[j+1];
            nums[j+1] = nums[j];
            nums[j] = tmp;
        }
    }
}

int main()
{
    vector<int> nums = {0,1,0,3,12};
    moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout <<nums[i] <<" ";
    }
    cout <<endl;
    return 0;
}