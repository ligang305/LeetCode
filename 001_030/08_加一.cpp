#include "iostream"
#include "vector"
#include "algorithm"
#include "math.h"
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int end = digits.size() - 1;
        for (int i = end; i >= 0; i--) {
            int item = digits[i];
            item++;
            if(item < 10){
                digits[i]++;
                return digits;
            }else{
               if(i > 0){
                   digits[i] = 0;
               } else{
                   digits[0] = 0;
                   digits.insert(digits.begin(), 1);
               }
            }
        }
        return digits;
    }
};

int main(){
//    输入：nums = [0,1,2,2,3,0,4,2], val = 2
//    输出：5, nums = [0,1,4,0,3]
//    {2} {3, 3} {3,4}
    Solution solution = Solution();
    vector<int> nums = {1,2,3};
    vector<int> res = solution.plusOne(nums);
    for (int i = 0; i < res.size(); ++i) {
        cout <<res[i] << " ";
    }
    cout << endl;
    return 0;
}
