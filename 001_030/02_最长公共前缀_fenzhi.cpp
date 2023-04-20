#include <iostream>
#include "vector"
#include "algorithm"
using namespace std;

string commonPrefix(string left, string right){
    int len = left.size() > right.size() ? right.size() : left.size();
    for (int i = 0; i < len; ++i) {
        if(left[i] != right[i]){
            return left.substr(0, i);
        }
    }
    return left.substr(0, len);
}

string longestCommonPrefix(vector<string>& strs, int start, int end) {
    if(start == end){
        return strs[start];
    }else{
        int mid = (start + end) / 2;
        string leftCP = longestCommonPrefix(strs, start, mid);
        string rightCP = longestCommonPrefix(strs, mid+1, end);
        return commonPrefix(leftCP, rightCP);
    }
}

//输入：strs = ["flower","flow","flight"]
//输出："fl"
string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 0) return "";
    else{
        return longestCommonPrefix(strs, 0, strs.size()-1);
    }
}

int main()
{
    vector<string> strs = {"a"};
    cout <<longestCommonPrefix(strs) <<endl;
    return 0;
}

