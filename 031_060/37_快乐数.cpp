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

bool isHappy1(int n) {
    vector<int> nums;
    int count = 0;
    do
    {
        nums.clear();
        //将n处理后放入nums中
        while (n > 0)
        {
            nums.push_back(n % 10);
            n /= 10;
        }

        //计算nums中数的平方和
        for (int i = 0; i < nums.size(); i++)
        {
            n += nums[i] * nums[i];
        }
        if(count > 100) return false;
        count++;
        
    } while (n != 1);
    
    return true;
}

int getNext(int n){
    int val = 0;
    while (n > 0)
    {
        int mod = n % 10;
        n /= 10;
        val += mod * mod;
    }
    return val;
}

bool isHappy(int n){
    //下一个数是1 
    unordered_set<int> m_set;
    while(n != 1){
        if(m_set.find(n) != m_set.end()) return false;
        m_set.emplace(n);
        n = getNext(n);
    }
    return true;
}

int main(){
    cout <<isHappy(19) <<endl;
    return 0;
}