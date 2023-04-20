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

// 1 2 3 4 5 6 8 9...
void next_ugly_num(vector<long> &nums)
{
    long end_num = nums[nums.size() - 1];
    long two_x = 0, three_x = 0, five_x = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        long num = nums[i];
        long num_2 = 2 * num;
        long num_3 = 3 * num;
        long num_5 = 5 * num;

        if (num_2 > end_num && two_x == 0)
            two_x = num_2;
        if (num_3 > end_num && three_x == 0)
            three_x = num_3;
        if (num_5 > end_num && five_x == 0)
            five_x = num_5;
        if (two_x > 0 && three_x > 0 && five_x > 0)
            break;
    }
    nums.emplace_back(min(min(two_x, three_x), five_x));
}

int nthUglyNumber1(int n)
{
    vector<long> nums;
    nums.emplace_back(1);
    for (size_t i = 1; i < n; i++)
    {
        next_ugly_num(nums);
    }
    return nums[n - 1];
}

int nthUglyNumber2(int n)
{
    priority_queue<long, vector<long>, greater<long>> q;
    unordered_set<long> m_set;
    q.push(1);
    m_set.emplace(1);
    // 从堆中取出 堆顶元素a, 算出2a, 3a, 5a并存入堆中，循环n次.
    int times = 1;
    while (times < n)
    {
        long top = q.top();
        q.pop();
        vector<long> three_nums = {2, 3, 5};
        for (auto num : three_nums)
        {
            long num_x = num * top;
            if (m_set.count(num_x) == 0)
            {
                m_set.emplace(num_x);
                q.push(num_x);
            }
        }
        times++;
    }
    return q.top();
}


int nthUglyNumber(int n)
{
    vector<int> nums(n+1, 0);
    nums[1] = 1;
    int p2 = 1, p3 = 1, p5 = 1;
    for (int i = 2; i < n+1; i++)
    {
        int num_2 = nums[p2] * 2;
        int num_3 = nums[p3] * 3;
        int num_5 = nums[p5] * 5;
        int num_min = min(min(num_2, num_3), num_5);
        nums[i] = num_min;
        if(num_2 == num_min) p2++;
        if(num_3 == num_min) p3++;
        if(num_5 == num_min) p5++;
    }
    return nums[n];
}


int main()
{
    cout << nthUglyNumber(7) << endl;
    cout << "很快啊." << endl;
    return 0;
}