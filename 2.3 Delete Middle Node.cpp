/******************************************************************************
Delete Middle node
Implement an algorithm to delete a node in the middle (any node but the first
and the last node, not necessarily the exact middle) of a Singly-Linked list,
given only access to that node.
Example 
Input: the node c from the linked list a->b->c->d->e->from
Result: nothing is returned, but the new linked list looks like a->b->d->e->f
*******************************************************************************/
#include <stdio.h>
#include <iostream>

using namespace std;

// Definition of Singly-Linked List
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


void deleteMiddleNode(ListNode* node){
    if(!node || node->next == NULL) {    // shouldnt be the last one
        return;
    }
    node->val = node->next->val;
    node->next = node->next->next;
}

// Print list
void printList(ListNode* head){
    while(head){
        cout << head->val;
        if(head->next != NULL){
            cout << "->";
        }
        head = head->next;
    }
    cout << endl;
}

int main()
{
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5); 
    ListNode n6(6);
    ListNode n7(7);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;
    cout << "Original list: ";
    printList(&n1);
    cout << "New List: ";
    deleteMiddleNode(&n4);
    printList(&n1);
    return 0;
}
