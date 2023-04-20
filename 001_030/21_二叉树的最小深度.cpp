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

int minDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    queue<pair<TreeNode *, int> > que;
    que.emplace(root, 1);
    while (!que.empty()) {
        TreeNode *node = que.front().first;
        int depth = que.front().second;
        que.pop();
        if (node->left == nullptr && node->right == nullptr) {
            return depth;
        }
        if (node->left != nullptr) {
            que.emplace(node->left, depth + 1);
        }
        if (node->right != nullptr) {
            que.emplace(node->right, depth + 1);
        }
    }

    return 0;
}

int minDepthMe(TreeNode* root) {
    queue<TreeNode *> Q;
    if(root == nullptr) return 0;
    int res = 0;
    Q.emplace(root);
    while(!Q.empty()){
        int size = Q.size();
        res++;
        while(size > 0){
            TreeNode * p = Q.front();
            if(p->left == nullptr && p->right == nullptr){
                return res;
            }
            Q.pop();
            if(p->left) Q.emplace(p->left);
            if(p->right) Q.emplace(p->right);
            size--;
        }
    }
    return 0;
}



int main(){
    TreeNode * root = new TreeNode(0);
    TreeNode * one = new TreeNode(1);
    TreeNode * two = new TreeNode(2);
    TreeNode * three = new TreeNode(3);
    TreeNode * four = new TreeNode(4);
    root->right = one;
    one->right = two;
    two->right = three;
    three->right = four;
    cout << minDepth(root) <<endl;
    return 0;
}
