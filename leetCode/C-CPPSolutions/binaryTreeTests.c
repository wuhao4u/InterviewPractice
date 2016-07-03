#include <stdio.h>
#include <stdbool.h>
#include "binaryTreeLib.h"
#include "binaryTreeTests.h"

void build123Test() {
    struct TreeNode* test1 = build123a();
    struct TreeNode* test2 = build123b();
    struct TreeNode* test3 = build123c();

    printf("%d\n", test3->val);
    printf("%d\n", test3->left->val);
    printf("%d\n", test3->right->val);
}

void sizeTest() {
    struct TreeNode* test = build123c();
    struct TreeNode* test1 = buildSampleBST(1);
    printf("size of the tree 123 is %d.\n", size(test));
    printf("size of the sample BST is %d\n", size(test1));
}

void maxDepthTest() {
    // struct TreeNode* head = build123a();
    struct TreeNode* head = buildSampleBST(1);
    printf("size of the list: %d\n", size(head));
    printf("depth of the list: %d\n", maxDepth(head));
}

void minValueTest() {
    struct TreeNode* testList = buildSampleBST(1);
    // struct TreeNode* testList = build123c();
    printf("Minimum value of the BST tree is %d by iterative function.\n", minValue_iter(testList));
    printf("Minimum value of the BST tree is %d by recursive function.\n", minValue_recur(testList));
}

void printTreeTest() {
    struct TreeNode* test = build123c();
    printTree(test);
    printf("---\n");

    struct TreeNode* test1 = buildSampleBST(1);
    printTree(test1);
    printf("---\n");
}

void printPostorderTest() {
    struct TreeNode* test = build123c();
    printPostorder(test);
    printf("---\n");

    struct TreeNode* test1 = buildSampleBST(1);
    printPostorder(test1);
    printf("---\n");    

    struct TreeNode* test2 = buildSampleBST(2);
    printPostorder(test2);
    printf("---\n");
}

void hasPathSumTest() {
    struct TreeNode* test = buildSampleBST(1);
    struct TreeNode* test1 = build123c();
    printTree(test);
    printTree(test1);
    printf("---\n");

    bool res = hasPathSum(test, 24);
    printf("%s\n", res ? "true" : "false");

    bool res1 = hasPathSum(test1, 5);
    // printf("bool: %d\n", res1);
    printf("%s\n", res1 ? "true" : "false");

    bool res2 = hasPathSum(test, 45);
    printf("%s\n", res2 ? "true" : "false");
}

void printPathsTest() {
    struct TreeNode* test = buildSampleBST(1);
    printPaths(test);
    printf("---\n");
    struct TreeNode* test1 = build123c();
    printPaths(test1);
}

void mirrorTest() {
    struct TreeNode* test = buildSampleBST(2);
    // struct TreeNode* test = build123c();
    printTree(test);
    printf("---after mirror\n");
    mirror(test);
    printTree(test);    
}

void doubleTreeTest() {
    // struct TreeNode* test = buildSampleBST(1);
    struct TreeNode* test = build123c();
    printTree(test);
    printf("---after doubling\n");
    doubleTree(test);
    printTree(test);
}

void sameTreeTest() {
    // struct TreeNode* t1 = build123a();
    // struct TreeNode* t2 = build123b();

    struct TreeNode* t1 = buildSampleBST(1);
    struct TreeNode* t2 = buildSampleBST(1);

    printf("---tree1\n");
    printTree(t1);
    printf("---tree2\n");
    printTree(t2);
    printf("---Are the 2 tree same?\n");
    printf("%s\n", sameTree(t1, t2) ? "true" : "false");
}

void countTreesTest() {
    int numKeys = 0;
    while(1) {
        printf("Enter a value: ");
        scanf("%d", &numKeys);
        printf("count tree result: %d\n", countTrees(numKeys));
    }
}

void isBSTTest() {
    struct TreeNode* bst = buildSampleBST(2);
    struct TreeNode* bst1 = build123c();
    struct TreeNode* bt = buildSampleBinaryTree();
    printf("bst: isBST? %s\n", isBST(bst) ? "true" : "false");
    printf("bst1: isBST? %s\n", isBST(bst1) ? "true" : "false");
    printf("bt: isBST? %s\n", isBST(bt) ? "true" : "false");
}

void isBST2Test() {
    struct TreeNode* bst = buildSampleBST(2);
    struct TreeNode* bst1 = build123c();
    struct TreeNode* bt = buildSampleBinaryTree();
    printf("bst: isBST2? %s\n", isBST2(bst) ? "true" : "false");
    printf("bst1: isBST2? %s\n", isBST2(bst1) ? "true" : "false");
    printf("bt: isBST2? %s\n", isBST2(bt) ? "true" : "false");
}