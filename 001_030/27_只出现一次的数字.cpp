#include "iostream"
#include "queue"
#include "stack"
#include "math.h"
#include "algorithm"

using namespace std;

//输入：nums = [4,1,2,1,2]
//输出：4
int singleNumber(vector<int>& nums) {
    int size = nums.size();
    if(size == 1) return nums[0];

    sort(nums.begin(), nums.end());
    if(nums[0] != nums[1]) return nums[0];
    if (nums[size-1] != nums[size - 2]) return nums[size-1];
    for (int i = 1; i < size-1; ++i) {
        if (nums[i] != nums[i-1] && nums[i] != nums[i+1]) return nums[i];
    }
    return 0;
}

int main(){
    /*vector<int> nums = {};
     *
    cout << singleNumber(nums) <<endl;*/

    cout <<(32 ^ 31) <<endl;
    return 0;
}
