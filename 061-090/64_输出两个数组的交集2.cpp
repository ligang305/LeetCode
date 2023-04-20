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

// 输入：nums1 = [1,3,3,1], nums2 = [3,3]
// 输出：[3,3]
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    // 用map实现 
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int p1 = 0, p2 = 0;
    vector<int> res;
    while(p1 < nums1.size() && p2 < nums2.size()){
        int num1 = nums1[p1];
        int num2 = nums2[p2];
        if(num1 < num2) p1++;
        else if(num1 > num2) p2++;
        else {
            res.push_back(num1);
            p1++;
            p2++;
        }
    }
    return res;
}

vector<int> intersect2(vector<int> &nums1, vector<int> &nums2)
{
    // 用map实现 
    unordered_map<int, int> m_map;
    for(auto i : nums1) m_map[i]++;
    vector<int> res; 
    for(auto i : nums2){
        if(m_map.count(i) && m_map[i]){
            res.push_back(i);
            m_map[i]--;
        }
    }
    return res;
}


vector<int> intersect1(vector<int> &nums1, vector<int> &nums2)
{
    int arr1[1001] = {0};
    int arr2[1001] = {0};
    for (int i = 0; i < nums1.size(); i++){
        int num = nums1[i];
        if(num >= 0 && num <= 1000) arr1[num]++;
    }
        
    for (int i = 0; i < nums2.size(); i++){
        int num = nums2[i];
        if(num >= 0 && num <= 1000) arr2[num]++;
    }
    vector<int> res;
    for (int i = 0; i < 1001; i++) {
        int num1 = arr1[i];
        int num2 = arr2[i];
        if(num1 && num2) for (int j = 0; j < min(num1, num2); j++) res.push_back(i);
    }
    return res;
}


int main()
{
    vector<int> nums1{1,3,3,1};
    vector<int> nums2{3,3};
    for(int i : intersect(nums1, nums2)) cout <<i <<" ";
    cout <<endl;
    return 0;
}