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

bool isAnagram1(string s, string t) {
    unordered_map<char, int> s_map, t_map;
    for (int i = 0; i < s.size(); i++)
    {
        s_map[s[i]]++;
    }
    for (int i = 0; i < t.size(); i++)
    {
        t_map[t[i]]++;
    }
    if(s_map.size() != t_map.size()) return false;
    for (auto item = s_map.begin(); item != s_map.end(); item++)
    {
        if(item->second != t_map[item->first]) return false;
    }
    return true;
}

bool isAnagram2(string s, string t) {
    if(s.length() != t.length()) return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

bool isAnagram(string s, string t) {
    vector<int> nums(26, 0);
    for (int i = 0; i < s.size(); i++)
    {
        nums[s[i]-'a']++;
    }

    for (int i = 0; i < t.size(); i++)
    {
        int index = t[i]-'a';
        nums[index]--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (nums[i] != 0)
        {
            return false;
        }
        
    }
    return true;
}

int main(){
    cout <<isAnagram("a", "ab") <<endl;
    return 0;
}