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

int hammingWeight2(uint32_t n) {
    int count = 0;
    while(n > 0)
    {
        if(n % 2) count++;
        n = n/2;
    }
    return count;
}

int hammingWeight(uint32_t n) {
    int count = 0;
    for(int i = 0; i < 32; i++)
    {
        if(n & (1 << i)){
            count++;
        }
    }
    return count;
}

int main(){
    // uint32_t a = 2147483647; 
    // cout <<reverseBits(2) <<endl;
    // cout <<(2 & 1) <<endl;
    cout <<hammingWeight(8) <<endl;
    return 0;
}