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

class MyQueue1 {
private:
    stack<int> m_stack;
    stack<int> tmp_stack;
public:
    MyQueue1() {

    }
    
    void push(int x) {
        while (!m_stack.empty())
        {
            int top = m_stack.top();
            m_stack.pop();
            tmp_stack.push(top);
        }
        m_stack.push(x);
        while (!tmp_stack.empty())
        {
            int top = tmp_stack.top();
            tmp_stack.pop();
            m_stack.push(top);
        }
    }
    
    int pop() {
        int top = m_stack.top();
        m_stack.pop();
        return top;
    }
    
    int peek() {
        return m_stack.top();
    }
    
    bool empty() {
        return m_stack.empty();
    }
};

class MyQueue {
private:
    stack<int> in_stack, out_stack;
public:
    MyQueue() {

    }

    void in2out(){
        while(!in_stack.empty()){
            int top = in_stack.top();
            in_stack.pop();
            out_stack.push(top);
        }
    }
    
    void push(int x) {
        in_stack.push(x);
    }
    
    int pop() {
        if(out_stack.empty()){
            in2out();
        }
        int top = out_stack.top();
        out_stack.pop();
        return top;
    }
    
    int peek() {
        if(out_stack.empty()){
            in2out();
        }
        return out_stack.top();
    }
    
    bool empty() {
        return in_stack.empty() && out_stack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main(){
    cout <<"hello 47" <<endl;
    return 0;
}