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
#include <bitset>
using namespace std;

bool isPowerOfFour(int n)
{
    return n > 0 && (n &(n-1)) == 0 && (n & 0xaaaaaaaa) == 0;
}

int main()
{
    cout << isPowerOfFour(16) <<endl;
    return 0;
}