#include "iostream"
#include "vector"
#include "algorithm"
#include "math.h"
#include "unordered_map"
using namespace std;

//输入：n = 2
//输出：2----> 1+1, 2
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 3) return n;
        int p = 1, q = 2, r = 3;
        for (int i = 3; i < n; ++i) {
            p = q;
            q = r;
            r = p + q;
        }
        return r;
    }
};
int main(){
    Solution solution = Solution();
    for (int i = 1; i <= 16; ++i) {
        int res = solution.climbStairs(i);
        cout <<i <<"---hi--->" <<res <<endl;
    }


    return 0;
}
