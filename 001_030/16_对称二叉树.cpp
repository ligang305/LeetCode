#include "iostream"
#include "vector"
#include "queue"
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode():val(0), left(nullptr), right(nullptr){};
    TreeNode(int x):val(x), left(nullptr), right(nullptr){};
};

bool isEqual(TreeNode * left, TreeNode * right){
    if(left == nullptr && right == nullptr) return true;
    if(left == nullptr ^ right == nullptr) return false;
    if(left->val != right->val) return false;
    return isEqual(left->left, right->right) && isEqual(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    if(root == nullptr) return false;
    return isEqual(root->left, root->right);
}

bool isSymmetric(TreeNode* u, TreeNode * v) {
    queue<TreeNode *> m_queue;
    m_queue.push(u);
    m_queue.push(v);
    TreeNode *p, *q;
    while(!m_queue.empty()){
        p = m_queue.front(); m_queue.pop();
        q = m_queue.front(); m_queue.pop();
        if(p == nullptr && q == nullptr) return true;
        if(p == nullptr ^ q == nullptr) return false;
        if(p->val != q->val) return false;
        m_queue.push(p->left);
        m_queue.push(q->right);

        m_queue.push(p->right);
        m_queue.push(q->left);
    }
    return true;
}

int main(){
    vector<TreeNode *> nodes;
    nodes.push_back(nullptr);
    nodes.push_back(nullptr);
    cout <<nodes.size() <<endl;
    return 0;
}