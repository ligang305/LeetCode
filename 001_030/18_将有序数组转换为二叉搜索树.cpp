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

void preOrder(TreeNode* root){
    cout <<"前序遍历" <<endl;
    stack<TreeNode*> stack;
    TreeNode* treeNode = root;
    while (treeNode != NULL || !stack.empty() ){
        //迭代访问左孩子并入栈
        while (treeNode != NULL){
            cout <<" " <<treeNode->val;
            stack.push(treeNode);
            treeNode = treeNode->left;
        }
        //如果节点无左孩子，弹出栈顶顶点，访问节点右孩子
        if (!stack.empty()){
            TreeNode* node = stack.top();
            stack.pop();
            treeNode =node->right;
        }
    }
    cout <<endl;
}

TreeNode* doSortedArrayToBST(vector<int>& nums, int left, int right) {
    if(left > right) return nullptr;
    int mid = (left + right) / 2;
    TreeNode * root = new TreeNode(nums[mid]);
    root->left = doSortedArrayToBST(nums, left, mid-1);
    root->right = doSortedArrayToBST(nums, mid+1, right);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    TreeNode * root = doSortedArrayToBST(nums, 0, nums.size()-1);
    return root;
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

    vector<int> nums = {1,2,3,4,5};
    TreeNode * m_root = sortedArrayToBST(nums);
    preOrder(m_root);
    return 0;
}