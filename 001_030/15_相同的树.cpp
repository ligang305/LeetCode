// constructing stacks
#include <iostream>
#include "stack"
#include "unistd.h"
#include "vector"
#include "queue"
using namespace std;

struct TreeNode{
    int val;
    TreeNode *next;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), next(nullptr), left(nullptr), right(nullptr){};
    TreeNode(int x) : val(x), next(nullptr), left(nullptr), right(nullptr) {};
};

bool theSame(TreeNode * p, TreeNode * q){
    //如果p为空 q为空 return true;
    //p,q一个为空，一个不为空 return false;
    //p,q均不为空,层次遍历：
    if(p == nullptr && q == nullptr){
        return true;
    }
    if(p == nullptr ^ q == nullptr){
        return false;
    }
    queue<TreeNode *> que_p, que_q;
    que_p.push(p);
    que_q.push(q);
    while(!que_p.empty() || !que_q.empty()){
        if(que_p.empty() ^ que_q.empty()){
            return false;
        }
        TreeNode * front_p = que_p.front();
        TreeNode * front_q = que_q.front();
        if(front_p->val != front_q->val){
            return false;
        }
        que_p.pop();
        que_q.pop();
        if(front_p->left){
            que_p.push(front_p->left);
        }
        if(front_p->right){
            que_p.push(front_p->right);
        }
        if(front_q->left){
            que_q.push(front_q->left);
        }
        if(front_q->right){
            que_q.push(front_q->right);
        }
        if(front_p->left == nullptr ^ front_q->left == nullptr){
            return false;
        }
        if(front_p->right == nullptr ^ front_q->right == nullptr){
            return false;
        }
    }
    return true;
}


bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == nullptr && q == nullptr){
        return true;
    }else if(p == nullptr || q == nullptr){
        return false;
    }else if(p->val != q->val){
        return false;
    }else{
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
}

int main ()
{
//    输入：root = [1,null,2,3]
//    输出：[1,3,2]


    return 0;
}