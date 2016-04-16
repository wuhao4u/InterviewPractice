struct node* reverseList(struct node* head)
{
    struct node* current = head;
    struct node* reversed = NULL;
    struct node* tail = NULL;

    while(current != NULL) {
        if(reversed == NULL)
        {
            reversed = malloc(sizeof(struct node));
            reversed->data = current->data;
            reversed->next = NULL;
            tail = reversed;
        }
        else
        {
            reversed = malloc(sizeof(struct node));
            reversed->data = current->data;
            reversed->next = tail;
            tail = reversed;
        }

        current = current->next;
    }
    return reversed;
}