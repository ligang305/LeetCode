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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
  

TreeNode* invertTree(TreeNode* root) {
    //递归吧
    //先翻转左子树
    //再翻转右子树
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
    {
        return root;
    }
    TreeNode * left = invertTree(root->left);
    TreeNode * right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}

int main(){
    TreeNode * one = new TreeNode(1);
    TreeNode * two = new TreeNode(2);
    TreeNode * three = new TreeNode(3);
    two->left = three;
    three->left = one;
    invertTree(two);
    cout <<"ok..." <<endl;
    return 0;
}