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
#include <list>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> pre_order(TreeNode *root){
    stack<TreeNode *> m_stack, path_stack;
    TreeNode *p = root;
    vector<vector<int>> paths; 
    vector<int> path;
    while(p || !m_stack.empty()){
        while (p)
        {
            cout <<p->val <<"-->";
            /* if(p->left == nullptr && p->right == nullptr){
                path.clear();
                while(!m_stack.empty()){
                    TreeNode * item = m_stack.top();
                    path_stack.push(item);
                    path.emplace(path.begin(), item->val);
                }
                paths.emplace_back(path);
                while(!path_stack.empty()){
                    TreeNode * item = path_stack.top();
                    m_stack.push(item);
                }
            } */
            m_stack.push(p);
            p = p->left;
        }
        if(!m_stack.empty()){
            TreeNode *top = m_stack.top();
            p = top->right;
            m_stack.pop();
        }
    }
    return paths;
}

// 输入：root = [1,2,3,null,5]
// 输出：["1->2->5","1->3"]
vector<string> binaryTreePaths1(TreeNode* root) {
    if (root == nullptr)
    {
        return {};
    }
    if(root->left == nullptr && root->right == nullptr) return {to_string(root->val)};

    vector<string> left_paths = binaryTreePaths1(root->left);
    vector<string> right_paths = binaryTreePaths1(root->right);
    vector<string> res;
    if(left_paths.size() > 0){
        for (size_t i = 0; i < left_paths.size(); i++)
        {
            string left_path = left_paths[i];
            res.push_back(to_string(root->val) + "->" + left_path);
        }
        
    }
    if(right_paths.size() > 0){
        for (size_t i = 0; i < right_paths.size(); i++)
        {
            string right_path = right_paths[i];
            res.push_back(to_string(root->val) + "->" + right_path);
        }
    }
    return res;
}

// 输入：root = [1,2,3,null,5]
// 输出：["1->2->5","1->3"]
vector<string> binaryTreePaths2(TreeNode* root) {
    if (root == nullptr)
    {
        return {};
    }
    if(root->left == nullptr && root->right == nullptr) return {to_string(root->val)};

    vector<string> left_paths = binaryTreePaths2(root->left);
    vector<string> right_paths = binaryTreePaths2(root->right);
    vector<string> res;
    for (size_t i = 0; i < left_paths.size(); i++)
        res.push_back(to_string(root->val) + "->" + left_paths[i]);
    
    for (size_t i = 0; i < right_paths.size(); i++)
        res.push_back(to_string(root->val) + "->" + right_paths[i]);
    return res;
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> paths;
    if (root == nullptr)
    {
        return paths;
    }
    queue<TreeNode *> nodes_que;
    queue<string> path_que;
    nodes_que.push(root);
    path_que.push(to_string(root->val));
    while(!nodes_que.empty()){
        TreeNode * node = nodes_que.front();
        string path = path_que.front();
        nodes_que.pop();
        path_que.pop();
        if(node->left == nullptr && node->right == nullptr){
            paths.push_back(path);
        }
        if(node->left != nullptr){
            nodes_que.push(node->left);
            path_que.push(path + "->" + to_string(node->left->val));
        }
        
        if(node->right != nullptr){
            nodes_que.push(node->right);
            path_que.push(path + "->" + to_string(node->right->val));
        }
    }
    return paths;
}

int main()
{
    TreeNode *one = new TreeNode(1);
    TreeNode *two = new TreeNode(2);
    TreeNode *three = new TreeNode(3);
    TreeNode *four = new TreeNode(4);
    TreeNode *five = new TreeNode(5);
    TreeNode *six = new TreeNode(6);

    one->left = two;
    one->right = three;
    two->left = four;
    two->right = five;
    three->left = six;
    vector<string> paths = binaryTreePaths(one);
    /* for (int i = 0; i < paths.size(); i++)
    {
        for (int j = 0; j < paths[i].size(); j++)
        {
            cout << paths[i][j] <<" ";
        }
        cout <<endl;
    } */
    
    // cout <<paths.size() <<endl;
    for (size_t i = 0; i < paths.size(); i++)
    {
        cout <<paths[i] <<endl;
    }
    cout <<"很快啊." <<endl;
    return 0;
}