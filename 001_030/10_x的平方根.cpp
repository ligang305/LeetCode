#include "iostream"
#include "vector"
#include "algorithm"
#include "math.h"
#include "unordered_map"
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        //取初值： x
        if(x == 0) return 0;
        double start = double(x);
        while(true){
            double next = start / 2 + x /(2*start);
            double val = next * next - x;
            if(abs(next-start) < 1e-3){
                return int(next);
            }
            start = next;
        }
        return x;
    }
};

int main(){
//    输入:a = "11", b = "1"
//    输出："100"

    Solution solution = Solution();
    int x = 2;
    cout <<fabs(-1.24) <<endl;
    cout <<abs(-1.27) <<endl;
    for (int i = 1; i <= 16; ++i) {
        int res = solution.mySqrt(i);
        cout <<i <<"---hi--->" <<res <<endl;
    }


    return 0;
}
