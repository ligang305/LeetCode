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
using namespace std;

bool isPowerOfTwo(int n) {
    vector<int> bi_nums;
    while (n)
    {
        bi_nums.emplace_back(n % 2);
        n /= 2;
    }
    int count = 0;
    for (int i = 0; i < bi_nums.size(); i++)
    {
        if(bi_nums[i] == 1) count++;
    }
    
    return count==1;
}

int main(){
    cout << isPowerOfTwo(4) <<endl;
    return 0;
}