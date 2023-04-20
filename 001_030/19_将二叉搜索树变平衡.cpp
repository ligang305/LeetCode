#include "iostream"
#include "vector"
#include "stack"
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode():val(0), left(nullptr), right(nullptr){};
    TreeNode(int x):val(x), left(nullptr), right(nullptr){};
};

void inOrder(TreeNode* root, vector<int> &nums)
{
    stack<TreeNode*> s;
    while(root != nullptr || !s.empty()) {
        while(root != nullptr) {
            s.push(root);
            root = root->left;
        }
        if (!s.empty()) {
            root = s.top();
            nums.push_back(root->val);
            s.pop();
            root = root->right;
        }
    }
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    int size = nums.size();
    if(size == 0) return nullptr;
    int mid = size / 2;
    TreeNode * root = new TreeNode(nums[mid]);
    vector<int> left_nums;
    vector<int> right_nums;
    left_nums.assign(nums.begin(), nums.begin() + mid);
    right_nums.assign(nums.begin() + mid + 1, nums.end());
    root->left = sortedArrayToBST(left_nums);
    root->right = sortedArrayToBST(right_nums);
    return root;
}


TreeNode* balanceBST(TreeNode* root) {
    vector<int> nums;
    inOrder(root, nums);
    TreeNode * res_node = sortedArrayToBST(nums);
    return res_node;
}

int main(){
    return 0;
}