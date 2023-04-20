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

vector<string> summaryRanges1(vector<int>& nums) {
    vector<string> vec_str;
    for (int i = 0; i < nums.size(); )
    {
        string item = to_string(nums[i]);
        int j = i+1;
        for (; j < nums.size(); j++)
        {
            if(nums[j] > (nums[j-1] + 1)){ 
                if((j-i) > 1){
                    item += "->" + to_string(nums[j-1]);
                }
                i = j;
                break;
            }
            
        }
        if(j == nums.size()){
            if(j-i>1){
                item += "->" + to_string(nums[j-1]);
            }
            i = j;
        }
        vec_str.emplace_back(item);
    }
    return vec_str;
}

vector<string> summaryRanges2(vector<int>& nums) {
    vector<string> vec_str;
    if(nums.size() == 0) return vec_str;
    vector<int> tmp;
    tmp.emplace_back(nums[0]);
    for (int end = 1; end < nums.size(); end++)
    {
        //如果相邻元素值相差大于1： a: end-begin > 1---> item = [begin]->[end]
        if(nums[end] > nums[end-1] + 1){
            if(tmp.size() > 1){
                vec_str.push_back(to_string(tmp[0]) + "->" + to_string(tmp.back()));
            }else{
                vec_str.push_back(to_string(tmp[0]));
            }
            tmp.clear();
        }
        tmp.emplace_back(nums[end]);
    }
    if(tmp.size() > 1) vec_str.push_back(to_string(tmp[0]) + "->" + to_string(tmp.back()));
    else vec_str.push_back(to_string(tmp[0]));
    
    return vec_str;
}

vector<string> summaryRanges3(vector<int>& nums) {
    vector<string> vec_str;
    vector<int> tmp;
    int size = nums.size();
    for (int end = 0; end < size; end++)
    {
        tmp.emplace_back(nums[end]);
        //如果相邻元素值相差大于1： a: end-begin > 1---> item = [begin]->[end]
        if(end == (size-1) || nums[end+1] > nums[end] + 1){
            if(tmp.size() > 1){
                vec_str.push_back(to_string(tmp[0]) + "->" + to_string(tmp.back()));
            }else{
                vec_str.push_back(to_string(tmp[0]));
            }
            tmp.clear();
        }
    }
    return vec_str;
}

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> vec_str;
    int begin = 0;
    int size = nums.size();
    for (int end = 0; end < size; end++)
    {
        if(end == (size-1) || nums[end+1] > nums[end] + 1){
            if(end > begin){
                vec_str.push_back(to_string(nums[begin]) + "->" + to_string(nums[end]));
            }else{
                vec_str.push_back(to_string(nums[begin]));
            }
            begin = end+1;
        }
    }
    return vec_str;
}


int main(){
    // vector<int> nums = {-2147483648,-2147483647,2147483647};
    vector<int> nums = {1,2,4,6,7,9,10};

    vector<string> res = summaryRanges(nums);
    for (string s : res)
    {
        cout <<s <<endl;
    }
    
    return 0;
}