#include <iostream>
#include "vector"
#include "algorithm"
using namespace std;


bool isCommonPrefix(vector<string> &strs, int mid){
    string common = strs[0].substr(0, mid);
    for(int i = 0; i < mid; i++){
        for(int j = 1; j < strs.size(); j++){
            if(common[i] != strs[j][i]) return false;
        }
    }
    return true;
}

//输入：strs = ["flower","flow","flight"]
//输出："fl"
string longestCommonPrefix(vector<string>& strs) {
    //写一下思路：①：找出最短的单词 ②：二分查找
    if (!strs.size()) return "";
    int minlength = min_element(strs.begin(), strs.end(), [](const string &s, const string &t){return s.size() < t.size();})->size();
    int low = 0, high = minlength-1;
    while(low <= high){
        int mid = (low + high) / 2;
        //判断【0 mid】是否为前缀; 是-> low = mid+1; 不是-> 更新 high = mid 如果此时 low == high return [0 low]
        if(isCommonPrefix(strs, mid+1)) low = mid + 1;
        else {
            high = mid - 1;
        }
    }
    return strs[0].substr(0, low);
}



int main()
{
    vector<string> strs = {"a"};
    cout <<longestCommonPrefix(strs) <<endl;
    return 0;
}

