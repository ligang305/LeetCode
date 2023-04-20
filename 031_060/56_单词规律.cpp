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
using namespace std;

// 输入: pattern = "abba", s = "dog cat cat dog"
// 输出: true
bool wordPattern1(string pattern, string s) {
    unordered_map<char, string> m_map;
    unordered_set<string> m_set;
    //先分隔一下s
    vector<string> vec;
    string word = "";
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] != ' '){
            word += s[i];
        }
        if(s[i] == ' '){
            vec.push_back(word);
            word = "";
        }
    }
    vec.push_back(word);
    if(vec.size() != pattern.size()) return false;
    
    for (int i = 0; i < pattern.size(); i++)
    {
        if(m_map.count(pattern[i]) == 0){
            
            unordered_map<char, string>::iterator iter;
            for (iter = m_map.begin(); iter != m_map.end(); iter++)
            {
                if((*iter).second == vec[i]) return false;
            }
            m_map[pattern[i]] = vec[i];
            
        }else{
            // 先取出来 如果和vector中的不一样 返回false 如果一样 沙也不做
            if(m_map[pattern[i]] != vec[i]) return false;
        }
    }
    return true;
}

// 输入: pattern = "abba", s = "dog cat cat dog"
// 输出: true
bool wordPattern(string pattern, string s) {
    unordered_map<char, string> c2str;
    unordered_map<string, char> str2c;
    stringstream ss(s);
    string word = "";
    for (int i = 0; i < pattern.size(); i++)
    {
        ss >> word;
        if(c2str.count(pattern[i]) && word != c2str[pattern[i]]) return false;
        if(str2c.count(word) && pattern[i] != str2c[word]) return false;
        c2str[pattern[i]] = word;
        str2c[word] = pattern[i];
    }
    while(ss >> word) return false;
    return true;
}

int main()
{
    // cout <<"什么归" <<endl;
    cout <<wordPattern("abba", "dog cat cat") <<endl;
    return 0;
}