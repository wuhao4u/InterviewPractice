#include <iostream>
#include <iomanip>
#include "binaryTreeLib.h"
#include <vector>

using namespace std;

//前序遍历
void preorder(TreeNode *root, vector<int> &path)
{
    if(root != NULL)
    {
        path.push_back(root->val);
        preorder(root->left, path);
        preorder(root->right, path);
    }
}
//中序遍历
void inorder(TreeNode *root, vector<int> &path)
{
    if(root != NULL)
    {
        inorder(root->left, path);
        path.push_back(root->val);
        inorder(root->right, path);
    }
}
//后续遍历
void postorder(TreeNode *root, vector<int> &path)
{
    if(root != NULL)
    {
        postorder(root->left, path);
        postorder(root->right, path);
        path.push_back(root->val);
    }
}


//非递归前序遍历
void preorderTraversal(TreeNode *root, vector<int> &path)
{
    stack<TreeNode *> s;
    TreeNode *p = root;
    while(p != NULL || !s.empty())
    {
        while(p != NULL)
        {
            path.push_back(p->val);
            s.push(p);
            p = p->left;
        }
        if(!s.empty())
        {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
}
//非递归中序遍历
void inorderTraversal(TreeNode *root, vector<int> &path)
{
    stack<TreeNode *> s;
    TreeNode *p = root;
    while(p != NULL || !s.empty())
    {
        while(p != NULL)
        {
            s.push(p);
            p = p->left;
        }
        if(!s.empty())
        {
            p = s.top();
            path.push_back(p->val);
            s.pop();
            p = p->right;
        }
    }
}
//非递归后序遍历-迭代
void postorderTraversal(TreeNode *root, vector<int> &path)
{
    stack<TempNode *> s;
    TreeNode *p = root;
    TempNode *temp;
    while(p != NULL || !s.empty())
    {
        while(p != NULL) //沿左子树一直往下搜索，直至出现没有左子树的结点
        {
            TreeNode *tempNode = new TreeNode;
            tempNode->btnode = p;
            tempNode->isFirst = true;
            s.push(tempNode);
            p = p->left;
        }
        if(!s.empty())
        {
            temp = s.top();
            s.pop();
            if(temp->isFirst == true)   //表示是第一次出现在栈顶
            {
                temp->isFirst = false;
                s.push(temp);
                p = temp->btnode->right;
            }
            else  //第二次出现在栈顶
            {
                path.push_back(temp->btnode->val);
                p = NULL;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int[] test = {1,2,3,4,5,6,7,8,9};
    postorderTraversal(test);

    return 0;
}