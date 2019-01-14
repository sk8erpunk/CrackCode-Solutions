/******************************************************************************
intersection
Given two (Singly-Linked list) lists, determine if the two lists intersect.
Return the intersecting node. Note that the intersection is defined based on 
reference, not value. That is, if the kth node of the first linked list is the 
exact same node (by reference) as the jth node of the second linked list, the 
they are intersecting.
*******************************************************************************/
#include <stdio.h>
#include <iostream> 
#include <cmath> 

using namespace std;

// Definition of Singly-Linked List
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Returns list length and last node address
int findLength(ListNode* head, ListNode** last){
    int len = 1;
    while(head->next){
        len++;
        head = head->next;
    }
    *last = head;
    return len;
}

// Time complexity is O(N+M)) where N and M is the lengths accordingly
// Memory space is O(1)
ListNode* returnIntersection(ListNode* head1, ListNode* head2){
    if(!head1 || !head2)
        return NULL;

    ListNode* last1, *last2;
    int len1 = findLength(head1, &last1);
    int len2 = findLength(head2, &last2);

    // If both have a different last element then no intersection
    if(last1 != last2)
        return NULL;
  
    ListNode* pLong = len1 > len2 ? head1 : head2;
    ListNode* pShort = len1 > len2 ? head2 : head1;
    int steps = abs(len1 - len2); 
   
    // advance pLong 
    while(steps){
        pLong = pLong->next;
        steps--;
    }
    
    // compare addresses to find an intersection
    while(pLong != pShort){    
        pLong = pLong->next;
        pShort = pShort->next;
    }
    return pLong;                    
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
    // list1
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
    // list2
    ListNode m1(11);
    ListNode m2(10);
    ListNode m3(9);
    ListNode m4(8);
    m1.next = &m2;
    m2.next = &m3;
    m3.next = &m4;
    m4.next = &n4;
    
    cout << "List1: ";
    printList(&n1);
    
    cout << "List2: ";
    printList(&m1);
    
    ListNode* intersection = returnIntersection(&n1, &m1);
    cout << "Intersection: " << intersection->val;
    return 0;
}
