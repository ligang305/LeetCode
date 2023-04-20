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

// 输入：s = "hello"
// 输出："holle"

string reverseVowels(string s)
{
    auto is_vowel = [vowels = "aeiouAEIOU"s](char c){
        return vowels.find(c) != string::npos;
    };
    int left = 0, right = s.length() - 1;
    
    while (left < right)
    {
        while(!is_vowel(s[left]) && left < right) left++;
        while(!is_vowel(s[right]) && left < right) right--;
        swap(s[left], s[right]);
        left++;
        right--;
    }
    return s;
}

string reverseVowels3(string s)
{
    auto is_vowel = [vowels = "aeiouAEIOU"s](char c){
        return vowels.find(c) != string::npos;
    };
    int left = 0, right = s.length() - 1;
    
    char c_arr[s.size()];
    for(int i = 0; i < s.size(); i++) c_arr[i] = s[i];

    while (left < right)
    {
        while(is_vowel(c_arr[left]) && left < right) left++;
        while(is_vowel(c_arr[right]) && left < right) right--;
        swap(c_arr[left], c_arr[right]);
        left++;
        right--;
    }
    string res;
    for (int i = 0; i < s.size(); i++) res.push_back(c_arr[i]);
    return res;
}

string reverseVowels2(string s)
{
    unordered_set<char> m_set{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int left = 0, right = s.length() - 1;
    
    char c_arr[s.size()];
    for(int i = 0; i < s.size(); i++) c_arr[i] = s[i];

    while (left < right)
    {
        while(m_set.count(c_arr[left]) == 0 && left < right) left++;
        while(m_set.count(c_arr[right]) == 0 && left < right) right--;
        swap(c_arr[left], c_arr[right]);
        left++;
        right--;
    }
    string res;
    for (int i = 0; i < s.size(); i++) res.push_back(c_arr[i]);
    return res;
}

string reverseVowels1(string s)
{
    unordered_set<char> m_set{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int left = 0, right = s.length() - 1;
    vector<char> vec(s.size());
    for(int i = 0; i < s.size(); i++) vec[i] = s[i];
    while (left < right)
    {
        while(m_set.count(vec[left]) == 0 && left < right) left++;
        while(m_set.count(vec[right]) == 0 && left < right) right--;
        swap(vec[left], vec[right]);
        left++;
        right--;
    }
    string res;
    for(auto i : vec) res.push_back(i);
    return res;
}

int main()
{
    string s = "hello";
    cout <<reverseVowels(s) <<endl;
    return 0;
}