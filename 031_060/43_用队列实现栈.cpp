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

class MyStack1 {
private:
    queue<int> m_queue, tmp_queue;
public:
    MyStack1() {

    }
    
    void push(int x) {
        m_queue.emplace(x);
    }
    
    int pop() {
        //先将m_queue中的元素转移值tmp_queue中
        //转移至最后一个时，pop一下
        //将tmp_queue中的元素复原值m_queue中
        while(m_queue.size() != 1){
            int front = m_queue.front();
            tmp_queue.emplace(front);
            m_queue.pop();
        }
        int top = m_queue.front();
        m_queue.pop();
        while(!tmp_queue.empty()){
            int front = tmp_queue.front();
            m_queue.emplace(front);
            tmp_queue.pop();
        }
        return top;
    }
    
    int top() {
        return m_queue.back();
    }
    
    bool empty() {
        return m_queue.empty();
    }
};

class MyStack {
private:
    queue<int> m_queue, tmp_queue;
public:
    MyStack() {

    }
    
    void push(int x) {
        //先将x放到tmp_queue中
        //再将m_queue中的元素搬到tmp_queue中来
        //对掉两个队列
        tmp_queue.emplace(x);
        while (!m_queue.empty())
        {
            int front = m_queue.front();
            m_queue.pop();
            tmp_queue.push(front);
        }
        swap(tmp_queue, m_queue);
    }
    
    int pop() {
        int front = m_queue.front();
        m_queue.pop();
        return front;
    }
    
    int top() {
        return m_queue.front();
    }
    
    bool empty() {
        return m_queue.empty();
    }
};


/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main(){
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    int param_2 = obj->top();
    int param_3 = obj->pop();
    bool param_4 = obj->empty();
    cout <<param_2 <<" " <<param_3 <<" " <<param_4 <<endl;  

    return 0;
}