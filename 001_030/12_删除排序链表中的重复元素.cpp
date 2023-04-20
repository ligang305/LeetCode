#include "iostream"
#include "vector"
#include "algorithm"
#include "math.h"
#include "unordered_map"
using namespace std;


struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    //输入：head = [1,1,2]
    //输出：[1,2]
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        ListNode* cur = head;
        ListNode * next = head->next;
        while (next){
            if(next->val > cur->val){
                cur->next = next;
                cur = next;
            }
            next = next->next;
        }
        cur->next = nullptr;
        return head;
    }
};

int main(){
    Solution solution = Solution();
    // int res = solution.deleteDuplicates(i);
    ListNode *node1 = new ListNode(1);
    ListNode node2 = ListNode(1);
    ListNode node3 = ListNode(2);
    ListNode node4 = ListNode(2);
    ListNode node5 = ListNode(3);
    node1->next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    ListNode * res = solution.deleteDuplicates(node1);
    while (res){
        cout << res->val <<endl;
        res = res->next;
    }
    return 0;
}
