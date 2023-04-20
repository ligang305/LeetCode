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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
  
bool isPalindrome1(ListNode* head) {
    ListNode* p = head, *q = head;
    stack<ListNode *> nodes;
    while(p){
        nodes.push(p);
        p = p->next;
    }
    int i = 0;
    while (i < nodes.size())
    {
        if(q->val != nodes.top()->val) return false;
        q = q->next;
        nodes.pop();
    }
    return true;
}

ListNode *front;

void see_val(ListNode *node){
    if(node) {
        see_val(node->next);
        if(front && front->val == node->val){
            front = front->next;
        }
    }
}

bool isPalindrome(ListNode* head) {
    front = head;
    see_val(head);
    return front == nullptr;
}

int main(){
    ListNode *one = new ListNode(1);
    ListNode *two = new ListNode(3);
    ListNode *three = new ListNode(2);
    ListNode *four = new ListNode(1);
    one->next = two;
    two->next = three;
    three->next = four;
    cout <<isPalindrome(one) <<endl;
    return 0;
}