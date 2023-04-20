#include <iostream>
#include "stack"
#include "unistd.h"
#include "vector"
#include "queue"
#include "map"
#include "unordered_set"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle1(ListNode *head) {
    if(head == NULL) return false;
    map<ListNode *, int> pointer_map;
    ListNode * p = head;
    int i = 0;
    pointer_map[p] = i;
    p = p->next;
    while (p){
        map<ListNode *, int>::iterator iter = pointer_map.find(p);
        if (iter != pointer_map.end()){
            return true;
        }else{
            pointer_map[p] = ++i;
        }
        p = p->next;
    }
    return false;
}

bool hasCycle(ListNode *head) {
    ListNode * slow, * fast;
    if(head == nullptr || head->next == nullptr){
        return false;
    }
    slow = head;
    fast = head->next;
    while (slow != fast){
        if(fast->next == nullptr || fast->next->next == nullptr){
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}


int main ()
{
    ListNode * one = new ListNode(1);
    ListNode * two = new ListNode(2);
    ListNode * three = new ListNode(3);
    ListNode * four = new ListNode(4);
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = nullptr;
    cout << hasCycle(one) <<endl;
    return 0;
}