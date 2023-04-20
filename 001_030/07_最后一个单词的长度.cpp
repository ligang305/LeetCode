#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        int space = 0;
        for (int i = s.size() - 1; i > 0; --i) {
            if(s[i] == ' '){
                space++;
            }else{
                break;
            }
        }
        int end = s.size() - space - 1;
        for (int i = end; i >= 0; --i) {
            if(s[i] == ' '){
                return res;
            }else{
                res++;
            }
        }
        return res;
    }
};

int main(){
//    输入：nums = [0,1,2,2,3,0,4,2], val = 2
//    输出：5, nums = [0,1,4,0,3]
//    {2} {3, 3} {3,4}
    Solution solution = Solution();
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int res = solution.lengthOfLastWord("s");
    cout << res <<endl;

    cout << endl;
    return 0;
}
