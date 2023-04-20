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
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList1(ListNode* head) {
    stack<ListNode *> m_stack;
    while(head){
        m_stack.push(head);
        head = head->next;
    }
    ListNode * new_head = new ListNode(0);
    ListNode * end = new_head;
    while(!m_stack.empty())
    {
        end->next = m_stack.top();
        m_stack.pop();
        end = end->next;
    }
    end->next = nullptr;
    return new_head->next;    
}

ListNode* reverseList2(ListNode* head) {
    ListNode *new_head = new ListNode();
    while(head){
        ListNode *node = new ListNode(head->val);
        node->next = new_head->next;
        new_head->next = node;
        head = head->next;
    }
    return new_head->next;    
}

ListNode* reverseList3(ListNode* head) {
    ListNode *curr = NULL, *pre = head;
    while(pre){
        ListNode *t = pre->next;
        pre->next = curr;
        curr = pre;
        pre = t;
    }
    return curr;    
}

ListNode* reverseList(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;
    ListNode * new_head = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return new_head;    
}


int main(){
    ListNode *one = new ListNode(1);
    ListNode *two = new ListNode(2);
    ListNode *three = new ListNode(3);
    ListNode *four = new ListNode(4);
    ListNode *five = new ListNode(5);
    one->next = two;
    // two->next = three;
    // three->next = four;
    // four->next = five;

    
    ListNode *head = reverseList(one);
    while(head){
        cout <<head->val <<" ";
        head = head->next;
    }
    // cout <<isIsomorphic("paper", "title") <<endl;
    return 0;
}