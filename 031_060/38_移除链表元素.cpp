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

struct ListNode {
    int val;
    ListNode * next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode * next) : val(x), next(next) {}
};
  
// 输入：head = [1,2,6,3,4,5,6], val = 6
// 输出：[1,2,3,4,5]  
ListNode* removeElements1(ListNode *head, int val) {
    ListNode * new_head = head;
    while (new_head && new_head->val == val)
    {
        new_head = new_head->next;
    }
    if(new_head == NULL) return NULL;
    
    ListNode *p, *each;
    p = new_head;
    each = new_head->next;
    while(each){
        if(each->val == val){
            p->next = each->next;
        }else{
            p = p->next;
        }
        each = each->next;
    }
    return new_head;
}

ListNode* removeElements(ListNode *head, int val) {
    ListNode * new_head = new ListNode(0, head);
    ListNode * tmp = new_head;
    while(tmp->next){
        if(tmp->next->val == val){
            tmp->next = tmp->next->next;
        }else{
            tmp = tmp->next;
        }
    }
    return new_head->next;
}


int main(){
    ListNode *node_1 = new ListNode(1);
    ListNode *node_2 = new ListNode(2);
    ListNode *node_3 = new ListNode(2);
    ListNode *node_4 = new ListNode(1);
    // ListNode *node_5 = new ListNode(4);
    // ListNode *node_6 = new ListNode(5);
    // ListNode *node_7 = new ListNode(6);
    node_1->next = node_2;
    node_2->next = node_3;
    node_3->next = node_4;
    // node_4->next = node_5;
    // node_5->next = node_6;
    // node_6->next = node_7;
    ListNode *ptr = removeElements(node_1, 2);
    while(ptr != NULL){
        cout <<ptr->val <<" ";
        ptr = ptr->next;
    }
    return 0;
}