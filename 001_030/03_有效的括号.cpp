#include <iostream>
#include "vector"
#include "algorithm"
#include "stack"
#include "map"
using namespace std;

//输入：s = "()[]{}"
//输出：true
bool isValid(string s) {
    map<char, char> pairs = {{')','('}, {']', '['}, {'}', '{'}};
    stack<char> stk;
    for(char ch : s){
        if(ch == '(' || ch == '[' || ch == '{'){
            stk.push(ch);
        }else{
            if(stk.empty() || stk.top() != pairs[ch]){
                return false;
            }else{
                stk.pop();
            }
        }
    }
    return stk.empty();
}

int main()
{
    string s = isValid("]") ? "true" : "false";
    cout << s <<endl;
    return 0;
}

