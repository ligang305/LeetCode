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
using namespace std;

// 输入：nums = [1,2,3,1]
// 输出：true
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> m_set;
    for (int i = 0; i < nums.size(); i++)
    {
        if(m_set.find(nums[i]) != m_set.end()){
            return true;
        }
        m_set.emplace(nums[i]);
    }
    return false;
}

int main(){
    vector<int> nums = {1,2,2,4};
    cout <<containsDuplicate(nums) <<endl;
    return 0;
}