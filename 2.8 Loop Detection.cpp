/******************************************************************************
Loop Detection 
Given a circular linked list, implement an algorithm that returns the node at
beginning of the loop.
Example:
Input:  A->B->C->D->E->C
Output: C
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

// Time complexity is O(N)
// Memory space is O(1)
ListNode* hasCycle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){           
            ListNode* p = head;
            while(p != slow){
                slow = slow->next;
                p = p->next;
            }
            return slow;
        }
    }
    return NULL;
}

int main()
{
    ListNode n1('a');
    ListNode n2('b');
    ListNode n3('c');
    ListNode n4('d');
    ListNode n5('e'); 
    ListNode n6('f');
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n3;
    ListNode* loopStart = hasCycle(&n1);
    if(loopStart == NULL){
        cout << "List has no cycle!";
    } else {
        cout << (char)loopStart->val;
    }
    return 0;
}
