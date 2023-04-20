#include <iostream>
#include "stack"
#include "unistd.h"
#include "vector"
#include "queue"
#include "map"
#include "unordered_set"
#include "unordered_map"
#include <math.h>
#include "algorithm"
using namespace std;

// 输入：n = 00000010100101000001111010011100
// 输出：964176192
//      4294967295

//43261596--->964176192
uint32_t reverseBits1(uint32_t n) {
    vector<int> nums(32, 0);
    int index = 0;
    uint32_t res = 0;
    while (n > 0)
    {
        nums[index++] = n%2;
        n = n/2;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        res += pow(2, nums.size()-i-1) * nums[i];
    }
    return res;
}

uint32_t reverseBits(uint32_t n) {
    uint32_t rev = 0;
    for (int i = 0; i < 32 && n > 0; ++i) {
        rev |= (n & 1) << (31 - i);
        n >>= 1;
        cout <<"i == " <<i << " rev = " <<rev <<" n = " <<n <<endl;
    }
    return rev;
}


int main(){
    // uint32_t a = 2147483647; 
    cout <<reverseBits(2) <<endl;
    // cout <<(2 & 1) <<endl;
    return 0;
}