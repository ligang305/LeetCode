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
#include <sstream>
using namespace std;

//1 true
//2 true
//3 ture
//4 false
//5 true
//6 true
//7 true
//8 false
//9 true
//10 true
//11 true
bool canWinNim1(int n)
{
    if(n == 1 || n == 2 || n == 3) return true;
    return (canWinNim(n-1) == false || canWinNim(n-2) == false || canWinNim(n-3) == false);
}

bool canWinNim(int n)
{
    return (n % 4) > 0;
}

int main()
{
    // cout <<"什么归" <<endl;
    cout << canWinNim(100) << endl;
    return 0;
}