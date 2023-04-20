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

void reverseString(vector<char> &s)
{
    int size = s.size();
    for (size_t i = 0; i < size/2; i++)
    {
        char tmp = s[i];
        s[i] = s[size-i-1];
        s[size-i-1] = tmp;
    }
}

int main()
{
    vector<char> a{'a', 'b', 'c'};
    reverseString(a);
    for_each(a.begin(), a.end(), [=](int x){cout <<"haha..." <<(char)x <<endl;});
    return 0;
}