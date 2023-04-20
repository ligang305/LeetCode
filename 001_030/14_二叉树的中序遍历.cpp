// constructing stacks
#include <iostream>
#include "stack"
#include "unistd.h"
#include "vector"
using namespace std;

struct TreeNode{
    int val;
    TreeNode *next;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), next(nullptr), left(nullptr), right(nullptr){};
    TreeNode(int x) : val(x), next(nullptr), left(nullptr), right(nullptr) {};
};

// 二叉树中序遍历
void inOrder(TreeNode* root)
{
    cout <<"中序遍历" <<endl;
    stack<TreeNode*> s;
    while(root != nullptr || !s.empty()) {
        while(root != nullptr) {
            s.push(root);
            root = root->left;
        }
        if (!s.empty()) {
            root = s.top();
            cout <<" " <<root->val;
            s.pop();
            root = root->right;
        }
    }
    cout <<endl;
}

//二叉树的前序遍历
void preOrder(TreeNode* root){
    cout <<"前序遍历" <<endl;
    stack<TreeNode*> stack;
    TreeNode* TreeNode = root;
    while (TreeNode != NULL || !stack.empty() ){
        //迭代访问左孩子并入栈
        while (TreeNode != NULL){
            cout <<" " <<TreeNode->val;
            stack.push(TreeNode);
            TreeNode = TreeNode->left;
        }
        //如果节点无左孩子，弹出栈顶顶点，访问节点右孩子
        if (!stack.empty()){
            TreeNode* TreeNode = stack.top();
            stack.pop();
            TreeNode =TreeNode->right;
        }
    }
    cout <<endl;
}

//后序遍历
void postOrder(TreeNode * root){
    cout <<"后序遍历" <<endl;
    stack<TreeNode *> stack;
    TreeNode* p=root;
    TreeNode* r=NULL;
    while(!stack.empty()||p!=NULL)
    {
        while(p!=NULL)
        {
            stack.push(p);
            p=p->left;
        }
        p = stack.top();
        if(p->right!=NULL&&p->right!=r)
            p=p->right;//转向右子树
        else
        {
            p = stack.top();
            stack.pop();
            cout <<" " <<p->val;
            r=p;//标记右孩子已经访问过了
            p=NULL;//访问完一个结点之后需要置空，不置空的话又会把这个结点压进去
        }
    }
    cout <<endl;
}

int main ()
{
    //先构造一颗树
    TreeNode *TreeNode1 = new TreeNode(1);
    TreeNode *TreeNode2 = new TreeNode(2);
    TreeNode *TreeNode3 = new TreeNode(3);
    TreeNode *TreeNode4 = new TreeNode(4);
    TreeNode *TreeNode5 = new TreeNode(5);
    TreeNode1->left = TreeNode2;
    TreeNode1->right = TreeNode3;
    TreeNode2->left = TreeNode4;
    TreeNode2->right = TreeNode5;
    postOrder(TreeNode1);

//    输入：root = [1,null,2,3]
//    输出：[1,3,2]
    vector<int> res;


    return 0;
}