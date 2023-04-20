#include <iostream>
#include "stack"
#include "unistd.h"
#include "vector"
#include "queue"
#include "map"
#include "unordered_set"
#include "math.h"
#include "algorithm"
using namespace std;

char num_to_char(int num){
    if(num == 0) return 'Z';
    if(num == 1) return 'A';
    else return 'A' + (num-1);
}

// 输入：columnNumber = 1
// 输出："A"
string convertToTitle1(int columnNumber) {
    string s = "";
    while(true){
        int mod = columnNumber % 26;
        s.push_back(num_to_char(mod));
        mod = mod == 0? 26 : mod;
        columnNumber = (columnNumber - mod) / 26;
        if(columnNumber == 0) break;
    }
    return string(s.rbegin(), s.rend());
    
}

string convertToTitle(int columnNumber) {
    string res = "";
    while(columnNumber > 0){
        int mod = (columnNumber - 1) % 26 +1;
        res += (mod - 1) + 'A';
        columnNumber = (columnNumber - mod) / 26;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    cout <<convertToTitle(2147483647) <<endl;
    return 0;
}