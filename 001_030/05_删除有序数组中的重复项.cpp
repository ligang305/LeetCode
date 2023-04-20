#include "iostream"
#include "vector"

using namespace std;
class Solution {
public:
    //输入：nums = [0,0,1,1,1,2,2,3,3,4]
    //输出：5, nums = [0,1,2,3,4]
    int removeDuplicates(vector<int>& nums) {
        int num = nums[0];
        int index = 0;
        for(int i = 0; i < nums.size(); i++){
            int item = nums[i];
            if(item > num){
                index++;
                nums[index] = item;
                num = nums[i];
            }
        }
        return ++index;
    }
};

int main(){
    Solution solution = Solution();
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int res = solution.removeDuplicates(nums);
    cout <<"res = " <<res;
    return 0;
}
