#include "iostream"
#include "queue"
#include "stack"
#include "math.h"
#include "algorithm"

using namespace std;

//如果在将所有大写字符转换为小写字符、并移除所有 非字母数字字符 之后，
//短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。
//s = "A man, a plan, a canal: Panama"
bool isPalindrome1(string s) {
    string line;
    for (int i = 0; i < s.size(); ++i) {
        char item = s[i];
        if(isalnum(item)) line.push_back(tolower(item));
    }
    string reverse_line(line.rbegin(), line.rend());
    return line == reverse_line;
}

bool isPalindrome(string s) {
    //设计左右两个指针
    int left = 0;
    int right = s.size()-1;
    //默认不是回文串，遍历完left >= right，即为回文串
    while(left < right){
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;
        if(left < right){
            char left_char = tolower(s[left]);
            char right_char = tolower(s[right]);
            if(left_char == right_char){
                left++;
                right--;
            } else{
                return false;
            }
        }
    }
    return true;
}

int main(){
    string s = ".,";
    cout << isPalindrome(s) <<endl;
    return 0;
}
