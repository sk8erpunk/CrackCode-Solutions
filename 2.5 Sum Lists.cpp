/******************************************************************************
Sum Lists
You have two numbers represented by linked list, where each node contains single 
digit. The digits are stored in reverse order, such that the 1's digit is at the 
head of the list. write a function that adds the two numbers and returns the sum
as a linked list.
Example:
Input: 7->1->6 + 5->9->2. That is 617+295.
Output: 2->1->9. That is 912.
*******************************************************************************/
#include <stdio.h>
#include <iostream>

#define MAX_DIGIT 9

using namespace std;

// Definition of Singly-Linked List
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Aux function which recursively adds two nodes values
ListNode* sumListAux(ListNode* head1, ListNode* head2, int carry){
    if(!head1 && !head2){   
        if(carry){  // in case there is a carry at the end
            return new ListNode(carry);
        }
        return NULL;
    }
    
    ListNode* node = new ListNode(0);   // new node for sum
    int sum = carry;
    if(head1 != NULL){      
        sum += head1->val;
    }
    if(head2 != NULL){
        sum += head2->val;
    }
    node->val = sum % 10;   // in case > 9
    int d =  sum > MAX_DIGIT ? 1 : 0; // is there a carry?
    ListNode* next1 = head1 == NULL ? NULL : head1->next;
    ListNode* next2 = head2 == NULL ? NULL : head2->next;
    ListNode* newNode = sumListAux(next1, next2, d);    
    node->next = newNode;  
    return node;
}

ListNode* sumList(ListNode* head1, ListNode* head2){
    return sumListAux(head1, head2, 0);
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
// Free list
void destroyList(ListNode* head){
    ListNode* itr = head;
    while(itr){
        ListNode* temp = itr;
        itr = itr->next;
        delete temp;
    }
}
int main()
{
    ListNode n1(9);
    ListNode n2(9);
    ListNode n3(9);
    n1.next = &n2;
    n2.next = &n3;
    ListNode m1(9);
    ListNode m2(9);
    ListNode m3(9);
    m1.next = &m2;
    m2.next = &m3;
    cout << "List1: ";
    printList(&n1);
    cout << "List2: ";
    printList(&m1);
    ListNode* sumLinkedList = sumList(&n1,&m1);
    cout << "Sum List: ";
    printList(sumLinkedList);
    destroyList(sumLinkedList); // free list
    return 0;
}
