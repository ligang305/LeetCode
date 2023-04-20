#include <iostream>
#include "stack"
#include "unistd.h"
#include "vector"
#include "queue"
#include "map"
#include "unordered_set"
#include "unordered_map"
#include <cstring>
#include <math.h>
#include "algorithm"
#include <list>
#include <sstream>
#include <bitset>
using namespace std;

int isPerfectSquare(int num)
{
    int left = 1, right = num, mid = num;
    
    while (true)
    {
        /* int flag = guess(mid);
        if(flag == 0) return mid;
        else if(flag == 1) left = mid + 1;
        else right = mid - 1;
        mid = (left + right) / 2; */
    }
    
    return -1;
}

bool isPerfectSquare2(int num)
{
    int low = 1, high = num, mid = 0;
    while(low <= high){
        mid = (low + high)/2;
        // mid = low+(high-low) / 2;
        int t = num / mid;
        if(t == mid) return true;
        if(t > mid) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

// 

bool isPerfectSquare1(int num)
{
    double x = num;
    while((x*x - num) > 1e-10){
        x = (x+num/x)/2;
    }
    x = int(x);
    return x * x == num;
}

int main()
{
    cout << isPerfectSquare(2000105819) <<endl;
    // int a =0, b = 3, d = 9;
    // int c = a+(b-d)/2;
    // cout <<"c ----> " <<c <<endl;
    vector<int> vec;
    return 0;
}