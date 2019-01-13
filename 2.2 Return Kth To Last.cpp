/******************************************************************************
Return Kth to last
Implement an algorithm to find the kth to last element of a Singly-Linked list
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

/*  First solution
*   Count all the elements then jump Length-K and return node address
*   Time Complexity is O(N) where N is the list length
*	Memory space is O(1)
*/ 
ListNode* kThToLast(ListNode* head, int k){
    if(!head)
        return NULL;
    
    ListNode* itr = head;
    int len = 0;
    while(itr){
        len++;
        itr = itr->next;
    }
    int jumps = len - k;
    itr = head;
    while(jumps){
        itr = itr->next;
        jumps--;
    }
    return itr;
}

// Aux function to kThToLastRecursive
int kThToLastAux(ListNode* head, int k, ListNode** newHead){
    if(!head)
        return 0;
    int count = kThToLastAux(head->next,k,newHead) + 1;
    if(count == k)
        *newHead = head;
    return count;
}

/*  Second solution
*   Recusively count k elements from the last element then return address
*   Time Complexity is O(N)
*	Memory space is O(N) (Because of recursive) 
*/
ListNode* kThToLastRecursive(ListNode* head, int k){
    if(!head)
        return NULL;
    ListNode* newHead = NULL;
    kThToLastAux(head, k, &newHead);
    return newHead;
}

/*  Third solution
*   Use two counters with k elements away
*   Time Complexity is O(N)
*	Memory space is O(1)
*/ 
ListNode* kThToLastPointers(ListNode* head, int k){
	if(!head) return NULL;
	ListNode* p1 = head;
	ListNode* p2 = head;
	
	// Move p2 to be k elements away
	for(int i = 0; i < k; i++){
		if(!p2) 
			return NULL;
		p2 = p2->next;
	}
	
	while(p2){
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
	
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
    cout << "First solution: ";
    ListNode* head = kThToLast(&n1, 4);
    printList(head);
    cout << "Second solution (Recusively): ";
    head = kThToLastRecursive(&n1, 4);
    printList(head);
    return 0;
}
