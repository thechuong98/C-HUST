#include "linked_list.c"

node* middle(node* start, node* last)
{
    if (start == NULL)
        return NULL;
 
    node* slow = start;
    node* fast = start -> next;
 
    while (fast != last)
    {
        fast = fast -> next;
        if (fast != last)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
    }
 
    return slow;
}

node* binarySearch(node *head, int value)
{
    node* start = head;
    node* last = NULL;
 
    do
    {
        // Find middle
        node* mid = middle(start, last);
 
        // If middle is empty
        if (mid == NULL)
            return NULL;
 
        // If value is present at middle
        if (mid -> data == value)
            return mid;
 
        // If value is more than mid
        else if (mid -> data < value)
            start = mid -> next;
 
        // If value is less than mid.
        else
            last = mid;
 
    } while (last == NULL ||
             last -> next != start);
 
    // value not present
    return NULL;
}

int main(){
    node *head = newNode(1);
    head->next = newNode(4);
    insert(&head, 3, listLength(head)+1);
    insert(&head, 3, listLength(head)+1);
    insert(&head, 3, listLength(head)+1);
        insert(&head, 3, listLength(head)+1);

    head->next->next->next->next->next = newNode(10);
    int value = 7;
    if (binarySearch(head, value) == NULL)
        printf("Value not present\n");
    else
        printf("Present");
    return 0;
}