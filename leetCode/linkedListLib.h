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

// Link List Problems
int Count(struct ListNode* head, int element);
int GetNth(struct ListNode* head, int index);
void DeleteList(struct ListNode** headRef);
int Pop(struct ListNode** headRef);
void InsertNth(struct ListNode** headRef, int index, int data);
void SortedInsert(struct ListNode** headRef, struct ListNode* newNode);
void SortedInsert_hao(struct ListNode** headRef, struct ListNode* newNode);
void InsertSort(struct ListNode** headRef);
void Append(struct ListNode** aRef, struct ListNode** bRef);

void FrontBackSplit(struct ListNode* source, 
    struct ListNode** frontRef, struct ListNode** backRef);
void MoveNode(struct ListNode** destRef, struct ListNode** sourceRef);
void AlternatingSplit(struct ListNode* source,
    struct ListNode** aRef, struct ListNode** bRef);
struct ListNode* ShuffleMerge(struct ListNode* a, struct ListNode* b);
struct ListNode* ShuffleMerge_hao(struct ListNode* a, struct ListNode* b);

struct ListNode* SortedMerge(struct ListNode* a, struct ListNode* b);
#endif