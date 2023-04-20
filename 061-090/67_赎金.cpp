#include <iostream>
#include "stack"
#include "unistd.h"
#include "vector"
#include "queue"
#include "map"
#include "unordered_set"
#include "unordered_map"
#include <cstring>
#include <math.h>
#include "algorithm"
#include <list>
#include <sstream>
#include <bitset>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    vector<int> vec;
    vec.size();
    // if (magazine.size() < ransomNote.size())
    // {
        /* code */
    // }
    
    return true;
}

// 输入：ransomNote = "aa", magazine = "aab"
// 输出：true
bool canConstruct1(string ransomNote, string magazine) {
    unordered_map<char, int> m_map;
    for(char i : magazine) m_map[i]++;
    for(char i : ransomNote){
        unordered_map<char, int>::iterator iter = m_map.find(i);
        //找到了： 数字为0 return false 没找到 return false 数字大于0 减一处理
        if(iter != m_map.end() && m_map[i] > 0) m_map[i]--;
        else return false;
    }
    return true;
}

int main()
{

    // int a =0, b = 3, d = 9;
    // int c = a+(b-d)/2;
    // cout <<"c ----> " <<c <<endl;
    cout <<"赎金啊..." <<endl;
    return 0;
}