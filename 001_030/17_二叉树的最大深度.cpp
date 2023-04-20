#include "iostream"
#include "vector"
#include "stack"
#include "queue"
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode():val(0), left(nullptr), right(nullptr){};
    TreeNode(int x):val(x), left(nullptr), right(nullptr){};
};

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

int main(){
    TreeNode * root = new TreeNode(3);
    TreeNode * one = new TreeNode(9);
    TreeNode * two = new TreeNode(20);
    TreeNode * three = new TreeNode(15);
    TreeNode * four = new TreeNode(7);
    root->left = one;
    root->right = two;
    two->left = three;
    two->right = four;
    maxDepth(root);

    return 0;
}