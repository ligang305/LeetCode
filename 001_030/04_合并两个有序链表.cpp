#include <iostream>
#include "vector"
#include "algorithm"
#include "stack"
#include "map"
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//输入：l1 = [1,2,4], l2 = [1,3,4]
//输出：[1,1,2,3,4,4]
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode * p_begin = new ListNode(-1);
    ListNode * p_end = p_begin;
    while(list1 && list2){
        if(list1->val < list2->val){
            p_end->next = list1;
            list1 = list1->next;
        }else{
            p_end->next = list2;
            list2 = list2->next;
        }
        p_end = p_end->next;
    }
    p_end->next = list1 == nullptr ? list2 : list1;
    return p_begin->next;
}

int main()
{
    ListNode left1 = ListNode(1);
    ListNode left2 = ListNode(2);
    ListNode left3 = ListNode(4);
    left1.next = &left2;
    left2.next = &left3;

    ListNode right1 = ListNode(1);
    ListNode right2 = ListNode(3);
    ListNode right3 = ListNode(4);
    right1.next = &right2;
    right2.next = &right3;

    //ListNode right1 = ListNode();

    ListNode* res = mergeTwoLists(&left1, &right1);
    ListNode* pointer = res;
    while(pointer != nullptr){
        cout << pointer->val <<" ";
        pointer = pointer->next;
    }
    return 0;
}

