#include "iostream"
#include "queue"
#include "stack"
#include "math.h"
#include "algorithm"

using namespace std;

//输入：[7,1,5,3,6,4]
//输出：5
int maxProfit(vector<int>& prices) {
    int max = 0;
    int range_min = prices[0];
    for (int i = 0; i < prices.size(); ++i) {
        //prices[i]先和range_min比较，若prices[i] <= range_min: range_min = prices[i]; continue;
        //                           若prices[i] > range_min:  pro = prices[i]-range_min,
        //                                                     若pro > max则：max = pro
        if(prices[i] <= range_min) {
            range_min = prices[i];
            continue;
        }
        int pro = prices[i] - range_min;
        if(pro > max) max = pro;
    }
    return max;
}

int main(){
    vector<int> price = {7,1,5,3,6,4};
    int pro = maxProfit(price);
    cout <<pro <<endl;
    return 0;
}
