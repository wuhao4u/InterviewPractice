#include <iostream>
#include "binaryTreeLib.h"

using namespace std;

void build123Test() {
    // struct TreeNode* test = build123a();
    // struct TreeNode* test = build123b();
    struct TreeNode* test = build123c();

    cout << test->val << endl;
    cout << test->left->val << endl;
    cout << test->right->val << endl;
}

struct TreeNode* buildSampleBST() {
    struct TreeNode* root;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 14);
    root = insert(root, 13);

    return root;
}

int size(struct TreeNode* node) {
    int count = 1;
    if(node->left != NULL) {
        count += size(node->left);
    }

    if(node->right != NULL) {
        count += size(node->right);
    }

    return count;
}

int main(int argc, char const *argv[])
{
    // struct TreeNode* test = build123a();
    struct TreeNode* test = buildSampleBST();
    printf("size of the tree is %d.\n", size(test));

    return 0;
}