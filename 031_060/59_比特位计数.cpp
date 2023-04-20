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
#include <list>
#include <sstream>
#include <bitset>
using namespace std;

int count_one(int item){
    int ones = 0;
    while(item > 0){
        item &= item-1;
        ones++;
    }
    return ones;
}
// 输入：n = 5
// 输出：[0,1,1,2,1,2]
// [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14]
// [0,1,1,2,1,2,2,3,1,2,2, 3, 2, 3, 3]
vector<int> countBits(int n)
{
     vector<int> vec(n+1, 0);
     int high_bit = 0;
     for (int i = 1; i < vec.size(); i++)
     {
        if((i & (i-1)) == 0){
            high_bit = i;
        }
        vec[i] = vec[i-high_bit] + 1;
     }
     return vec;
}

vector<int> countBits2(int n)
{
     vector<int> vec(n+1, 0);
     for (int i = 0; i < vec.size(); i++)
     {
        vec[i] = count_one(i);
     }
     return vec;
}


vector<int> countBits1(int n)
{
    if(n == 0) return {0};
    if(n == 1) return {0,1};
    int k = 2, i = 2;
    vector<int> vec(n+1);
    vec[0] = 0;
    vec[1] = 1;
    while(i <= n){
        int j = 0;
        for (; j < k; j++)
        {
            vec[i+j] = vec[i+j-k] + 1;
            if(i+j == n) {
                return vec;
            }
        }
        i += j;
        k *= 2;
    }
    return vec;    
}

int main()
{
    vector<int> res = countBits(14);
    for (size_t i = 0; i < res.size(); i++)
    {
        cout << " " <<res[i];
    }
    cout <<endl;
    
    return 0;
}