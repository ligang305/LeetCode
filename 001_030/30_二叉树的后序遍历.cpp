#include <iostream>
#include "stack"
#include "unistd.h"
#include "vector"
#include "queue"
#include "map"
#include "unordered_set"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void post_order(TreeNode * root, vector<int> &res){
    if(root == nullptr){
        return;
    }
    post_order(root->left, res);
    post_order(root->right, res);
    res.push_back(root->val);
}

vector<int> postorderTraversal1(TreeNode* root) {
    vector<int> res;
    post_order(root, res);
    return res;
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    if(root == nullptr) return res;
    stack<TreeNode *> m_stack;
    TreeNode * prev = nullptr;
    while(root || !m_stack.empty()){
        while (root){
            m_stack.push(root);
            root = root->left;
        }
        root = m_stack.top();
        m_stack.pop();
        if(root->right && root->right != prev){
            m_stack.push(root);
            root = root->right;
        }else{
            res.push_back(root->val);
            prev = root;
            root = nullptr;
        }
    }
    return res;
}

int main ()
{
    TreeNode * one = new TreeNode(1);
    TreeNode * two = new TreeNode(2);
    TreeNode * three = new TreeNode(3);
    TreeNode * four = new TreeNode(4);
    one->left = two;
    one->right = three;
    two->left = four;
    vector<int> res = postorderTraversal(one);
    for (int i = 0; i < res.size(); ++i) {
        cout <<res[i] <<" ";
    }
    cout <<endl;
    return 0;
}