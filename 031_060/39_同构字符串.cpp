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

bool isIsomorphic(string s, string t) {
    if(s.size() != t.size()) return false;
    unordered_map<char, char> m_map;
    for (int i = 0; i < s.size(); i++)
    {
        //取出s[i]，查看m_map是否已存在
        //已存在：val一样。是ok的， val不一样 return false
        //不存在：如果vals中已存在，返回false添加
        char si = s[i];
        if(m_map.find(si) == m_map.end()){
            for(auto x : m_map){
                if(x.second == t[i]) return false;
            }
            m_map[si] = t[i];
        }else{
            if(m_map[si] != t[i]) return false;
            
        }
    }
    return true;
}

int main(){
    cout <<isIsomorphic("paper", "title") <<endl;
    return 0;
}