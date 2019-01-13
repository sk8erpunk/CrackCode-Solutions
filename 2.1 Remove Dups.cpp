/******************************************************************************
Remove Dups:
Write code to remove duplicates from an unsorted linked list.
FOLLOW UP 
How would you solve this problem if a temporary buffer is not allowed?
*******************************************************************************/
#include <stdio.h>
#include <set>
#include <iostream>

using namespace std;

// Definition of Singly-Linked List
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Remove duplicates using set 
// Time Complexity is O(N) where N is list length
// Memory space is O(N)
ListNode* removeDuplicates(ListNode* head){
    if(!head)
        return NULL;
    set<int> elements;
    ListNode* curr = head;
	ListNode* prev = NULL;
	while(curr){
		if(elements.find(curr->val) == elements.end()){
			elements.insert(curr->val);
			prev = curr;
			curr = curr->next;
		} else {
			curr = curr->next;
			prev->next = curr;
		}
	}
    return head;
}

// Remove duplicates without using additional memory space 
// Time Complexity is O(N^2)
// Memory space is O(1)
ListNode* removeDuplicatesNoBuffer(ListNode* head){
    if(!head)
        return NULL;
    
	ListNode* curr = head;
    while(curr) {
        ListNode* itr = curr->next;
        ListNode* prev = curr;
        while(itr){
            if(itr->val == curr->val){
				itr = itr->next;
                prev->next = itr;
            } else {
                prev = itr;
                itr = itr->next;
            }
        }
        curr = curr->next;
    }
    return head;
}

// Print list
void printList(ListNode* head){
    while(head){
        cout << head->val;
        if(head->next != NULL)
            cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    ListNode n1(2);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(3); 
    ListNode n6(1);
    ListNode n7(2);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;
    cout << "Original list: ";
    printList(&n1);
    cout << "No duplicates using buffer: ";
    ListNode* head = removeDuplicates(&n1);
    printList(head);
    cout << "No duplicates without buffer: ";
    head = removeDuplicatesNoBuffer(&n1);
    printList(head);
    return 0;
}
