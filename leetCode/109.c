#include <stdio.h>
#include <stdlib.h>
#include "linkedListLib.h"
#include "binaryTreeLib.h"

struct TreeNode* convertHelper(struct ListNode **head, int size) {
    if(size == 0) return NULL;

    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->left = convertHelper(head, size / 2);
    root->val = (*head)->val;
    printf("root val: %d\n", root->val);
    printf("size: %d\n", size);

    *head = (*head)->next;
    root->right = convertHelper(head, size - size / 2 - 1);
    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    if(head == NULL) return NULL;

    int size = Length(head);
    printf("size: %d\n", size);
    return convertHelper(&head, size);
}

int main(int argc, char const *argv[])
{
    struct ListNode* test = BuildByLength(20);
    struct TreeNode* res = sortedListToBST(test);

    PrintList(test);
    printf("---\n");
    printTree(res);
    return 0;
}