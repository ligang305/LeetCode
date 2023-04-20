#include <iostream>
#include "stack"
#include "unistd.h"
#include "vector"
#include "queue"
#include "map"
#include "unordered_set"
#include "unordered_map"
#include "math.h"
#include "algorithm"
using namespace std;

// 输入：nums = [2,2,1,1,1,2,2]
// 输出：2
int majorityElement(vector<int>& nums) {
    int candidate = -1;
    int count = 0;
    for (int num : nums) {
        if (num == candidate)
            ++count;
        else if (--count < 0) {
            candidate = num;
            count = 1;
        }
    }
    return candidate;
}

int main(){
    vector<int> nums = {1,1,1,2,2,2,2};
    cout <<majorityElement(nums) <<endl;
    return 0;
}