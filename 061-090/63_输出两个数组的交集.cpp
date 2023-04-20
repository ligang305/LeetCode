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

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> vec(1001, 0), res;
    for (int i = 0; i < nums1.size(); i++) vec[nums1[i]] = 1;
    for (int i = 0; i < nums2.size(); i++) if(vec[nums2[i]] == 1) {res.push_back(nums2[i]); vec[nums2[i]]++;}
    return res;
}

int main()
{
    vector<int> m_vec{11, 22, 33, 33, 66, 3};
    unordered_set<int> m_set{m_vec.begin(), m_vec.end()};
    for(int i : m_set) cout <<i <<" ";
    cout <<endl;
    return 0;
}