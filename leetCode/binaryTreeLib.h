#ifndef BINARY_TREE_LIB
#define BINARY_TREE_LIB

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode * right;
};

int lookup(struct TreeNode* node, int target);
struct TreeNode* newNode(int data);
struct TreeNode* insert(struct TreeNode* node, int data);

struct TreeNode* build123a();
struct TreeNode* build123b();
struct TreeNode* build123c();

#endif