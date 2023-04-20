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

// 输入：nums = [1,2,3,1], k = 3
// 输出：true
bool containsNearbyDuplicate1(vector<int>& nums, int k) {
    //用一个hashmap就可以了吧
    //拿到一个新元素a，先看a在hashmap中出现过没有
    //没有出现过：加入<a, index>
    //   出现过： 拿当前的index和map中的index作比。符合要求返回true; 不符合要求：替换为当前的index
    unordered_map<int, int> m_map;
    for (int i = 0; i < nums.size(); i++)
    {
        if(!m_map.count(nums[i]) || i-m_map[nums[i]] > k){
            m_map[nums[i]] = i;
        }else{
            return true;
        }
    }
    return false;
}

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> m_set;
    int len = nums.size();
    for (int i = 0; i < len; i++)
    {
        int num = nums[i];
        if(m_set.count(num)){
            return true;
        }
        m_set.emplace(num);
        if(i >= k) m_set.erase(nums[i-k]);
    }
    return false;
}

int main(){
    vector<int> nums = {1,2,3,1};
    cout <<containsNearbyDuplicate(nums, 3) <<endl;
    return 0;
}