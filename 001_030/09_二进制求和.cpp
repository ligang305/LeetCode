#include "iostream"
#include "vector"
#include "algorithm"
#include "math.h"
#include "unordered_map"
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int len = a.size() > b.size() ? a.size() : b.size();
        int carry = 0;
        string res("");
        for (int i = 0; i < len; ++i) {
             carry += i < a.size() ? a[i] == '1' : 0;
             carry += i < b.size() ? b[i] == '1' : 0;
             res.push_back(carry % 2 ? '1' : '0');
             carry /= 2;
        }
        if(carry){
            res.push_back('1');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
//    输入:a = "11", b = "1"
//    输出："100"
    Solution solution = Solution();
    string res = solution.addBinary("1010", "1011");
    cout <<res <<endl;
    return 0;
}
