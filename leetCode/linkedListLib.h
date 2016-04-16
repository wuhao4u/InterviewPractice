#ifndef LINKED_LIST_LIB
#define LINKED_LIST_LIB

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* BuildOneTwoThree();
struct ListNode* BuildByLength(int count);
int Length(struct ListNode* head);
void PrintList(struct ListNode* head);
void Push(struct ListNode** headRef, int val);
struct ListNode* CopyList(struct ListNode* head);
struct ListNode* reverseList(struct ListNode* head);
int Count(struct ListNode* head, int element);
int GetNth(struct ListNode* head, int index);
void DeleteList(struct ListNode** headRef);
int Pop(struct ListNode** headRef);

#endif