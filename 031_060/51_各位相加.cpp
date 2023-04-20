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
#include <list>
using namespace std;

void cal(int num, int &sum){
    int sum_ = 0;
    while (num > 0)
    {
        sum_ += num % 10;
        num /= 10;
    }
    sum = sum_;
}

int addDigits1(int num) {
    if(num < 10) return num;
    int sum = 0;
    while(true){
        cal(num, sum);
        if(sum < 10) return sum;
        swap(num, sum);
    }
    return 0;
}

int addDigits(int num) {
    while (num > 9)
    {
        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
        num = sum;
    }
    
    return num;
}

int main()
{
    cout <<addDigits(38) <<endl;
    cout <<"很快啊." <<endl;
    return 0;
}