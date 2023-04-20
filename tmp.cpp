#include <stdio.h>
#include <string.h>
#include "iostream"
#include "string"
#include "queue"
#include "stack"

using namespace std;
struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode():val(0), left(nullptr), right(nullptr){};
    TreeNode(int x):val(x), left(nullptr), right(nullptr){};
};

void depthAccess(TreeNode * p){
    stack<TreeNode *> p_stack;
    while (!p_stack.empty() || p){
        while(p){
            cout <<p->val  <<" " <<endl;
            p_stack.push(p);
            p = p->left;
        }
        if(!p_stack.empty()){
            TreeNode * tmp = p_stack.top();
            p_stack.pop();
            p = tmp->right;
        }
    }
}

bool depthAccess(TreeNode * p, TreeNode * q){
    if(p == nullptr && q == nullptr) return true;
    if(p == nullptr ^ q == nullptr) return false;
    stack<TreeNode *> p_stack;
    stack<TreeNode *> q_stack;
    while ((!p_stack.empty() || p) && (!p_stack.empty() || p)){
        while(p && q){
            if(p->val != q->val) return false;
            p_stack.push(p);
            q_stack.push(q);
            p = p->left;
            q = q->left;
        }
        if((!p_stack.empty()) && (!p_stack.empty())){
            TreeNode * tmp_p = p_stack.top();
            TreeNode * tmp_q = q_stack.top();
            p_stack.pop();
            q_stack.pop();
            p = tmp_p->right;
            q = tmp_q->right;
        }
    }
    return true;
}

void access(TreeNode * root){
    //用一个queue来辅助
    //root不为空，将root添加到queue中。
    //从queue中取出一个元素，访问，弹出。将该元素left存入queue, 将该元素right存入queue
    //循环，只要queue不为空
    queue<TreeNode *> que;
    if(root){
        que.push(root);
    }
    while(!que.empty()){
        TreeNode * front = que.front();
        cout <<front->val <<" ";
        que.pop();
        if(front->left){
            que.push(front->left);
        }
        if(front->right){
            que.push(front->right);
        }
    }
    cout <<endl;
}


int main(int argc, char const *argv[])
{
    TreeNode * root1 = new TreeNode(1);
    TreeNode * two = new TreeNode(2);

    TreeNode * three = new TreeNode(3);
    TreeNode * four = new TreeNode(4);
    TreeNode * five = new TreeNode(5);
    TreeNode * six = new TreeNode(6);

    root1->left = two;
    root1->right = three;
    two->left = four;
    two->right = five;
    three->right = six;

    depthAccess(root1);

    return 0;
}



