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

// 输入: columnTitle = "AB"
// 输出: 28
int titleToNumber1(string columnTitle) {
    int res = 0;
    int n = columnTitle.size();
    for (int i = 0; i < n; i++)
    {
        char num_char = columnTitle[i];
        res += pow(26, (n-i-1)) * (num_char - 'A' +1);
    }
    return res;
}

int titleToNumber(string columnTitle) {
    int res = 0;
    int n = columnTitle.size();
    int power = 1;
    for (int i = 0; i < n; i++)
    {
        if(i > 0) power *= 26;
        char num_char = columnTitle[n-i-1];
        res += power * (num_char - 'A' +1);
    }
    return res;
}

int main(){
    cout <<titleToNumber("FXSHRXW") <<endl;
    return 0;
}