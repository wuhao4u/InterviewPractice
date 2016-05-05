#include <stdlib.h>
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
    struct TreeNode* node = new(struct TreeNode);
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
    struct TreeNode* two = newNode(2);
    struct TreeNode* one = newNode(1);    
    struct TreeNode* three = newNode(3);

    two->left = one;
    two->right = three;
    return two;
}

struct TreeNode* build123b() {
    struct TreeNode* root = newNode(2);
    root->left = newNode(1);
    root->right = newNode(3);

    return root;
}

struct TreeNode* build123c() {
    struct TreeNode* root = NULL;
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 3);

    return root;
}