#include "iostream"
#include "vector"
#include "algorithm"
#include "math.h"
#include "unordered_map"
using namespace std;

class Solution {
public:
    //输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    //输出：[1,2,2,3,5,6]
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int cur = m+n - 1;
        int left = m - 1;
        int right = n - 1;
        while (true){
            if(right == -1) break;
            if(left == -1){
                for (int i = right; i >= 0; --i) {
                    nums1[cur] = nums2[right];
                    right--;
                    cur--;
                }
                break;
            }
            if(nums1[left] < nums2[right]){
                nums1[cur] = nums2[right];
                right--;
            }else{
                nums1[cur] = nums1[left];
                left--;
            }
            cur--;
        }
    }
};

int main(){
    Solution solution = Solution();
    //输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    //输出：[1,2,2,3,5,6]
    vector<int> nums1 = {1}, nums2 = {};
    int m = 1, n = 0;
    solution.merge(nums1, m, nums2, n);
    for (int i = 0; i < m + n; ++i) {
        cout <<nums1[i] <<" ";
    }
    return 0;
}
