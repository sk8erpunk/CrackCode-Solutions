/******************************************************************************
Partition
Write code to partition a linked list around a value x, such that all nodes less than x come
before all nodes greater than or equal to x. If x is contained within the list the values of x only need
to be after the elements less than x (see below). The partition element x can appear anywhere in the
"right partition"; it does not need to appear between the left and right partitions.
EXAMPLE
Input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition= 5]
Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8
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

// Time complexity is O(N) where N is list length
// Memory space is O(1)
ListNode* partition(ListNode* head, int p){
	if(!head)
		return NULL;
	ListNode* h = head;
	ListNode* t = head;
	ListNode* curr = head->next;
	while(curr){
		if(curr->val >= p){
			t->next = curr;
			t = t->next;
			curr = curr->next;
		} else {
			t->next = NULL;
			ListNode* temp = curr;
			curr = curr->next;
			temp->next = h;
			h = temp;
		}		
	}
	return h;
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
    ListNode n1(3);
    ListNode n2(5);
    ListNode n3(8);
    ListNode n4(5);
    ListNode n5(10); 
    ListNode n6(2);
    ListNode n7(1);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;
    cout << "Original list: ";
    printList(&n1);
    cout << "New List: ";
    ListNode* newList = partition(&n1,8);
    printList(newList);
    return 0;
}