#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = nums.size();
        while(left < right){
            if(nums[left] == val){
                nums[left] = nums[right - 1];
                right--;
            }else{
                left;
            }
        }
        return left;
    }
};

int main(){
//    输入：nums = [0,1,2,2,3,0,4,2], val = 2
//    输出：5, nums = [0,1,4,0,3]
//    {2} {3, 3} {3,4}
    Solution solution = Solution();
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int res = solution.removeElement(nums, 2);
    cout << res <<endl;
    for(int i = 0; i < nums.size(); i++){
        cout <<nums[i] << " ";
    }
    cout << endl;
    return 0;
}
