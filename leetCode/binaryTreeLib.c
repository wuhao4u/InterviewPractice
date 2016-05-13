#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
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
    return(root);
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

        // case 3:
        //     root = newNode(5);
        //     struct TreeNode* rl = newNode(4);
        //     struct TreeNode* rr = newNode(8);
        //     root->left = rl;
        //     root->right = rr;

        //     struct TreeNode* rll = newNode(11);
        //     struct TreeNode* rlll = newNode(7);
        //     struct TreeNode* rllr = newNode(2);
        //     rll->left = rlll;
        //     rll->right = rllr;

        //     struct TreeNode* rrl = newNode(13);
        //     struct TreeNode* rrr = newNode(4);
        //     rr->left = rrl;
        //     rr->right = rrr;

        //     struct TreeNode* rrrr = newNode(1);
        //     rrr->right = rrrr;
        //     break;
        default:
            break;

    }

    return root;
}

struct TreeNode* buildSampleBinaryTree() {
    struct TreeNode* root;

    root = newNode(2);
    struct TreeNode* seven = newNode(7);
    struct TreeNode* five = newNode(5);
    struct TreeNode* two = newNode(2);
    struct TreeNode* six = newNode(6);
    struct TreeNode* nine = newNode(9);
    struct TreeNode* five1 = newNode(5);
    struct TreeNode* eleven = newNode(11);
    struct TreeNode* four = newNode(4);

    root->left = seven;
    root->right = five;
    seven->left = two;
    seven->right = six;
    six->left = five1;
    six->right = eleven;
    five->right = nine;
    nine->left = four;

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

int maxValue(struct TreeNode* root) {
    struct TreeNode* current = root;

    while(current->right != NULL) {
        current = current->right;
    }
    return current->val;
}

void printTree(struct TreeNode* node) {
    if(node == NULL) return;
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

static void printPathsRecur(struct TreeNode* node, int path[], int pathLen) {
    // printf("here[%d]: %d, wat[%d]\n", pathLen, node->val, path[pathLen]);

    if(!node) return;
    path[pathLen] = node->val;
    if((!node->left) && (!node->right)) {
        for (int i = 0; i < pathLen + 1; ++i) {
            printf("%d ", path[i]);
        }
        printf("\n");
    }
    else {        
        if (node->left)
            printPathsRecur(node->left, path, pathLen+1);
        if (node->right)
            printPathsRecur(node->right, path, pathLen+1);
    }
}

void printPaths(struct TreeNode* node) {
    if(!node) return;
    else {
        // the longest path possible is not going to exceed the max depth of the tree
        int path[maxDepth(node)];
        printPathsRecur(node, path, 0);
    }
}

void mirror(struct TreeNode* node) {
    struct TreeNode* temp = NULL;
    if(node->left || node->right) {
        temp = node->left;
        node->left = node->right;
        node->right = temp;

        if(node->left) mirror(node->left);
        if(node->right) mirror(node->right);
    }
}

void doubleTree(struct TreeNode* node) {
    if(node->left) doubleTree(node->left);
    if(node->right) doubleTree(node->right);

    struct TreeNode* temp = node->left;
    struct TreeNode* dup = newNode(node->val);
    dup->left = temp;
    node->left = dup;
}

int sameTree(struct TreeNode* a, struct TreeNode* b) {
    int selfBool, leftBool, rightBool;

    selfBool = (a->val == b->val);

    if(a->left && b->left) {
        leftBool = sameTree(a->left, b->left);
    } else {
        if((!a->left) && (!b->left)) leftBool = true;
        else leftBool = false;
    }

    if(a->right && b->right) {
        rightBool = sameTree(a->right, b->right);
    } else {
        if((!a->right) && (!b->right)) rightBool = true;
        else rightBool = false;
    }

    return (selfBool && leftBool && rightBool);
}

int countTrees(int numKeys) {
    // catalan number
    int result = 0;
    if(numKeys == 0 || numKeys == 1) {
        result = 1;
    }
    else {
        for (int i = 1; i < numKeys+1; ++i) {
            result += countTrees(i - 1) * countTrees(numKeys - i);
        }
    }
    return result;
}

int isBST(struct TreeNode* node) {
    if(node == NULL) return true;

    if(node->left != NULL && maxValue(node->left) > node->val)
        return false;

    if(node->right != NULL && minValue_iter(node->right) <= node->val)
        return false;

    if(!isBST(node->left) || !isBST(node->right))
        return false;

    return true;
}

static int isBSTRecur(struct TreeNode* node, int min, int max) {
    if(!node) return true;

    if(node->val < min || node->val > max) return false;

    return isBSTRecur(node->left, min, node->val) 
        && isBSTRecur(node->right, node->val + 1, max);
}

int isBST2(struct TreeNode* node) {
    return isBSTRecur(node, INT_MIN, INT_MAX);
}
