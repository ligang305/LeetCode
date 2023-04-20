#include <iostream>
#include "stack"
#include "unistd.h"
#include "vector"
#include "queue"
#include "map"
#include "unordered_set"
#include "math.h"
using namespace std;


struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
    if(headA == headB) return headA;
    //弄两个栈
    stack<ListNode *> stack_a, stack_b;
    while (headA != nullptr){
        stack_a.push(headA);
        headA = headA->next;
    }
    while (headB != nullptr){
        stack_b.push(headB);
        headB = headB->next;
    }
    //将stack_a，stack_b中的栈顶元素取出，作比，
    //如果相等，出栈，并作标记 pre
    //如果不等，返回pre
    ListNode * pre = nullptr;
    while(!stack_a.empty() && !stack_b.empty()){
        ListNode * top_a = stack_a.top();
        ListNode * top_b = stack_b.top();
        if(top_a == top_b){
            stack_a.pop();
            stack_b.pop();
            if(stack_a.empty() || stack_b.empty()) return top_a;
            pre = top_a;
            continue;
        }
        return pre;
    }
    return NULL;
}

ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB){
    if(headA == nullptr || headB == nullptr) return nullptr;
    ListNode *p_a = headA, *p_b = headB;
    //p_a, p_b同步前行, 谁先走到尽头，换一条路走
    while(p_a != p_b){
        p_a = p_a == nullptr ? headB : p_a->next;
        p_b = p_b == nullptr ? headA : p_b->next;
    }
    return p_a;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
    //先算一下两个链表的长度，使得两个链表同步
    int len_a = 0, len_b = 0;
    ListNode * p_a = headA, *p_b = headB;
    while (p_a)
    {
        len_a++;
        p_a = p_a->next;
    }
    while (p_b)
    {
        len_b++;
        p_b = p_b->next;
    }
    p_a = headA;
    p_b = headB;
    if(len_a > len_b){
        for(int i = 0; i < len_a - len_b; i++) p_a = p_a->next;
    }else {
        for(int i = 0; i < len_b - len_a; i++) p_b = p_b->next;
    }
    while(p_a != p_b){
        p_a = p_a->next;
        p_b = p_b->next;
    }
    return p_a;
}

int main(){
    ListNode a_one(1);
    ListNode a_two(2);
    ListNode b_one(9);
    ListNode b_two(10);
    ListNode a_b_one(11);
    ListNode a_b_two(12);
    a_one.next = &a_two;
    a_two.next = &a_b_one;
    a_b_one.next = &a_b_two;
    b_one.next = &b_two;
    b_two.next = &a_b_one;
    cout << getIntersectionNode(&a_one, &b_one)->val <<endl;
    return 0;
}