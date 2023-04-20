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

bool hasPathSum_1(TreeNode* root, int targetSum) {
    if(!root){
        return false;
    }
    queue<TreeNode *> queue_node;
    queue<int> queue_val;
    queue_node.push(root);
    queue_val.push(root->val);
    while(!queue_node.empty()){
        TreeNode * front_node = queue_node.front();
        int front_val = queue_val.front();
        queue_node.pop();
        queue_val.pop();
        if(front_node->left == nullptr && front_node->right == nullptr && front_val == targetSum){
            return true;
        }
        if(front_node->left){
            queue_node.push(front_node->left);
            queue_val.push(front_node->left->val + front_val);
        }
        if(front_node->right){
            queue_node.push(front_node->right);
            queue_val.push(front_node->right->val + front_val);
        }
    }
    return false;
}

bool hasPathSum(TreeNode* root, int targetSum) {
    if(!root){
        return false;
    }
    typedef pair<TreeNode *, int> Pair;
    queue<Pair> queue_node;
    queue_node.push(Pair(root, root->val));
    while(!queue_node.empty()){
        Pair front_node = queue_node.front();
        queue_node.pop();
        if(front_node.first->left == nullptr && front_node.first->right == nullptr && front_node.second == targetSum){
            return true;
        }
        if(front_node.first->left){
            queue_node.push(Pair(front_node.first->left, front_node.second + front_node.first->left->val));
        }
        if(front_node.first->right){
            queue_node.push(Pair(front_node.first->right, front_node.second + front_node.first->right->val));
        }
    }
    return false;
}


int main(){
    TreeNode * root = new TreeNode(5);
    TreeNode * one = new TreeNode(4);
    TreeNode * two = new TreeNode(8);
    TreeNode * three = new TreeNode(11);
    TreeNode * four = new TreeNode(13);
    TreeNode * five = new TreeNode(4);
    TreeNode * six = new TreeNode(7);
    TreeNode * seven = new TreeNode(2);
    TreeNode * eight = new TreeNode(1);
    root->left = one;
    root->right = two;
    one->left = three;
    two->left = four;
    two->right = five;
    three->left = six;
    three->right = seven;
    five->left = eight;
    cout <<hasPathSum(root, 22) <<endl;
    return 0;
}
