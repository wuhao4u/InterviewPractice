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
struct TreeNode* buildSampleBST();
int size(struct TreeNode* node);
int maxDepth(struct TreeNode* node);
int minValue_iter(struct TreeNode* root);
int minValue_recur(struct TreeNode* root);
void printTree(struct TreeNode* node);
void printPostorder(struct TreeNode* node);
int hasPathSum(struct TreeNode* node, int sum);

#endif