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

vector<vector<int>> res;
vector<int> row;

vector<vector<int>> generate(int numRows) {
    return res;
}

vector<vector<int>> generate3(int numRows) {
    vector<vector<int>> res(numRows);
    for (int i = 0; i < numRows; ++i) {
        res[i].resize(i+1);
        res[i][0] = res[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            res[i][j] = res[i-1][j-1] + res[i-1][j];
        }
    }
    return res;
}

vector<vector<int>> generate2(int numRows) {
    vector<vector<int>> res;
    //思路：还是双层for循环，第一层循环：每循环一次，生成一个vector放入res中
    //                      内层循环：利用对称的性质，每次赋值两次
    for (int i = 0; i < numRows; ++i) {
        vector<int> vec_item(i+1);
        for (int j = 0; j <= (i + 1) / 2; ++j) { //j = 0 1 1 2 2 3 3 4 4
            if(i == 0 || i == 1 || j == 0){
                vec_item[j] = vec_item[i-j] = 1;
                continue;
            }
            vec_item[j] = vec_item[i-j] = res[i-1][j] + res[i-1][j-1];
        }
        res.push_back(vec_item);
    }
    return res;
}

vector<vector<int>> generate1(int numRows) {
    vector<vector<int>> res;
    //还是要写一下思路：外循环numRows次，每一次外循环结束，构建杨辉三角中的一行并添加到res中
    for (int i = 0; i < numRows; ++i) {

        vector<int> vec_item;
        vec_item.push_back(1);
        if (i == 0){
            res.push_back(vec_item);
            continue;
        }
        if (i == 1){
            vec_item.push_back(1);
            res.push_back(vec_item);
            continue;
        }

        vector<int> last = res[i-1];
        for (int j = 1; j < i; ++j) {
            vec_item.push_back(last[j-1] + last[j]);
        }
        vec_item.push_back(1);
        res.push_back(vec_item);
    }
    return res;
}

int main(){
    vector<vector<int>> res = generate3(40);
    for (int i = 0; i < res.size(); ++i) {
        vector<int> item = res[i];
        for (int j = 0; j < item.size(); ++j) {
            cout <<item[j] <<" ";
        }
        cout <<endl;
    }
    return 0;
}
