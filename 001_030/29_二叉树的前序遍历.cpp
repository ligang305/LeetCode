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

vector<int> preorderTraversal1(TreeNode* root) {
    stack<TreeNode *> m_statck;
    vector<int> res;
    TreeNode * p = root;
    while(!m_statck.empty() || p != nullptr){
        while(p != nullptr){
            res.push_back(p->val);
            m_statck.push(p);
            p = p->left;
        }
        if(!m_statck.empty()){
            TreeNode * top = m_statck.top();
            p = top->right;
            m_statck.pop();
        }
    }
    return res;
}

void preorder(TreeNode * root, vector<int> &nodes){
    if(root == nullptr){
        return;
    }
    nodes.push_back(root->val);
    preorder(root->left, nodes);
    preorder(root->right,nodes);
}

vector<int> preorderTraversal0(TreeNode* root) {
    vector<int> res;
    preorder(root, res);
    return res;
}

vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    if (root == nullptr) {
        return res;
    }

    TreeNode *p1 = root, *p2 = nullptr;

    while (p1 != nullptr) {
        p2 = p1->left;
        if (p2 != nullptr) {
            while (p2->right != nullptr && p2->right != p1) {
                p2 = p2->right;
            }
            if (p2->right == nullptr) {
                res.emplace_back(p1->val);
                p2->right = p1;
                p1 = p1->left;
                continue;
            } else {
                p2->right = nullptr;
            }
        } else {
            res.emplace_back(p1->val);
        }
        p1 = p1->right;
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
    vector<int> res = preorderTraversal(one);
    for (int i = 0; i < res.size(); ++i) {
        cout <<res[i] <<" ";
    }
    cout <<endl;
    return 0;
}