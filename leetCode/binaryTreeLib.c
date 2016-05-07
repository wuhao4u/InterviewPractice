#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binaryTreeLib.h"

int lookup(struct TreeNode* node, int target) {
    // 1. Base case == empty tree
    // in that case, the target is not found so returen false
    if (node == NULL) {
        return(false);
    }
    else {
        // 2. see if found here
        if (target == node->val) return (true);
        else {
            // 3. otherwise recur down the correct subtree
            if (target < node->val) return(lookup(node->left, target));
            else return(lookup(node->right, target));            
        }
    }
}

/*
Helper function that allocates a new node 
with the given data and NULL left and right 
pointers.
*/
struct TreeNode* newNode(int data) {
    // struct TreeNode* node = new(struct TreeNode);
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

/*
Give a binary search tree and a number, inserts a new node
with the given number in the corrrect place in the tree.
Returns the new root pointer which the caller should
then use (the standard trick to avoid using reference
parameters).
*/
struct TreeNode* insert(struct TreeNode* node, int data) {
    // 1. If the tree is empty return a new, single node
    if (node == NULL) {
        return(newNode(data));
    }
    else {
        // 2. Otherwise, recur down the tree
        if (data <= node->val) node->left = insert(node->left, data);
        else node->right = insert(node->right, data);

        return(node); // return the unchanged node pointer
    }
}

// question 1
struct TreeNode* build123a() {
    struct TreeNode* root = newNode(2);
    struct TreeNode* lChild = newNode(1);    
    struct TreeNode* rChild = newNode(3);

    root->left = lChild;
    root->right = rChild;
    return(root);
}

struct TreeNode* build123b() {
    struct TreeNode* root = newNode(2);
    root->left = newNode(1);
    root->right = newNode(3);

    return(root);
}

struct TreeNode* build123c() {
    struct TreeNode* root = NULL;
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 3);
    return root;
}

struct TreeNode* buildSampleBST(int option) {
    struct TreeNode* root = NULL;

    switch(option) {
        case 1:
            root = insert(root, 8);
            root = insert(root, 3);
            root = insert(root, 10);
            root = insert(root, 1);
            root = insert(root, 6);
            root = insert(root, 4);
            root = insert(root, 7);
            root = insert(root, 14);
            root = insert(root, 13);
            break;

        case 2:            
            root = insert(root, 4);
            root = insert(root, 2);
            root = insert(root, 5);
            root = insert(root, 1);
            root = insert(root, 3);
            break;

        case 3:
            root = newNode(5);
            struct TreeNode* rl = newNode(4);
            struct TreeNode* rr = newNode(8);
            root->left = rl;
            root->right = rr;

            struct TreeNode* rll = newNode(11);
            struct TreeNode* rlll = newNode(7);
            struct TreeNode* rllr = newNode(2);
            rll->left = rlll;
            rll->right = rllr;

            struct TreeNode* rrl = newNode(13);
            struct TreeNode* rrr = newNode(4);
            rr->left = rrl;
            rr->right = rrr;

            struct TreeNode* rrrr = newNode(1);
            rrr->right = rrrr;
            break;
        default:
            break;

    }

    return root;
}

int size(struct TreeNode* node) {
    if (node == NULL) {
        return (0);
    } else {
        return(size(node->left) + 1 + size(node->right));
    }
}

int maxDepth(struct TreeNode* node) {
    if (node == NULL) {
        return(0);
    }
    else {
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);

        return lDepth > rDepth ? lDepth+1 : rDepth+1;
    }
}

int minValue_iter(struct TreeNode* root) {
    struct TreeNode* current = root;
    int min = current->val;

    while(current->left != NULL) {
        current = current->left;
        min = current->val;
    }
    return min;
}

int minValue_recur(struct TreeNode* root) {
    if (root->left) return minValue_recur(root->left);
    else return root->val;
}

void printTree(struct TreeNode* node) {
    if(node->left != NULL) printTree(node->left);
    printf("%d\n", node->val);
    if(node->right != NULL) printTree(node->right);
}

void printPostorder(struct TreeNode* node) {
    if(node->left != NULL) printPostorder(node->left);
    if(node->right != NULL) printPostorder(node->right);
    printf("%d\n", node->val);
}

int hasPathSum(struct TreeNode* node, int sum) {
    if(!node) return 0;

    if(node->val == sum) {
        return 1;
    }
    else {
        int lRes = 0, rRes = 0;

        if(node->left != NULL)
            lRes = hasPathSum(node->left, sum - node->val);

        if(node->right != NULL)
            rRes = hasPathSum(node->right, sum - node->val);

        return (lRes || rRes);
    }
}
