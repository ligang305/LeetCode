#include "iostream"
#include "queue"
#include "stack"
#include "math.h"

using namespace std;

//输入: numRows = 5
//输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
/*
          1
        1   1
      1   2   1
    1   3   3   1
  1   4   6   4   1
1   5   10  10  5   1
 */

//Cn(m) = n! / m! (n-m)!
int c_n_m(int n, int m){
    int sum1 = 1;
    int sum2 = 1;
    for (int i = 1; i <= n - m; ++i) {
        sum1 *= n-i+1;
        sum2 *= i;
    }
    int res = sum1 / sum2;
    return res;
}

vector<int> getRow(int rowIndex) {
    vector<int> res(rowIndex+1);
    for (int i = 0; i < rowIndex + 1; ++i) {
        if(i > rowIndex/2)
            res[i] = c_n_m(rowIndex, i);
        else
            res[i] = c_n_m(rowIndex, rowIndex-i);
    }
    return res;
}

vector<int> getRow1(int rowIndex) {
    vector<int> pre, cur;
    //滚动数组
    for (int i = 0; i < rowIndex+1; ++i) {
        cur.resize(i+1);
        cur[0] = cur[i] = 1;
        for (int j = 1; j < i+1; ++j) {
            cur[j] = pre[j-1] + pre[j];
        }
        pre = cur;
    }
    return pre;
}

vector<int> getRow2(int rowIndex) {
    vector<int> row(rowIndex + 1);
    row[0] = 1;
    for (int i = 1; i <= rowIndex; ++i) {
        for (int j = i; j > 0; --j) {
            row[j] += row[j - 1];
        }
    }
    return row;
}

vector<int> getRow3(int rowIndex) {
    vector<int> row(rowIndex + 1);
    row[0] = 1;
    for (int i = 1; i <= rowIndex; ++i) {
        row[i] = 1LL * row[i-1] * (rowIndex - i + 1)/(i);
    }
    return row;
}

int main(){
    int k = 1LL;
    vector<int> item = getRow3(40);
    for (int j = 0; j < item.size(); ++j) {
        cout <<item[j] <<" ";
    }
    return 0;
}
