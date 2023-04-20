#include "iostream"
#include "queue"
#include "stack"
#include "math.h"

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode():val(0), left(nullptr), right(nullptr){};
    TreeNode(int x):val(x), left(nullptr), right(nullptr){};
};

/*
public boolean isBalanced(TreeNode root) {
    if(root==null) return true;
    if(Math.abs(depth(root.left)-depth(root.right))>1) return false;
    return isBalanced(root.right)&&isBalanced(root.left);
}
public int depth(TreeNode root){
    if(root==null) return 0;
    return Math.max(depth(root.left)+1,depth(root.right)+1);
}
 */

int depth(TreeNode * root){
    if(root == nullptr) return 0;
    int left = depth(root->left);
    int right = depth(root->right);
    return max(left, right) + 1;
}

bool isBalanced(TreeNode * root){
    if(root == nullptr) return true;
    int left_depth = depth(root->left);
    int right_depth = depth(root->right);
    if(abs(left_depth - right_depth) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}

int maxDepth(TreeNode* root) {
    queue<TreeNode *> Q;
    if(root == nullptr) return 0;
    int res = 0;
    Q.push(root);
    while(!Q.empty()){
        int size = Q.size();
        res++;
        while(size > 0){
            TreeNode * p = Q.front();
            Q.pop();
            if(p->left) Q.push(p->left);
            if(p->right) Q.push(p->right);
            size--;
        }
    }
    return res;
}

bool isBalanced(TreeNode* root) {
    bool balanced = true;
    stack<TreeNode*> s;
    while(root != nullptr || !s.empty()) {
        while(root != nullptr) {
            s.push(root);
            root = root->left;
        }
        if (!s.empty()) {
            root = s.top();
            int hight_left = maxDepth(root->left);
            int hight_right = maxDepth(root->right);
            if(abs(hight_left-hight_right) > 1) return false;
            s.pop();
            root = root->right;
        }
    }
    return balanced;
}

int main(){
    return 0;
}
