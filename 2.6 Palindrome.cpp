/******************************************************************************
Palindrome 
Implement a function to check if a linked list is a palindrome.   
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

ListNode* isPalindromeAux(ListNode* p1, ListNode* p2){
    if(!p2->next)											// if reached last element
		return p1->val == p2->val ? p1->next : NULL;		// compare p1 val to p2 val
    
    ListNode* next = isPalindromeAux(p1, p2->next);			// move p2 to last element
    if(next && next->val == p2->val)   						// if ok until now and current pair is equal
		return next->next;									// then move p1 
    else 
		return NULL; 										// not equal 
}

// Time complexity is O(N) where N is list length
// Memory space is O(N) 
bool isPalindrome(ListNode* head){
    if(!head || !head->next)// Empty list or one element
        return true;   
    return isPalindromeAux(head,head->next) == NULL ? false : true;
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
    ListNode n4(5);
    ListNode n5(3); 
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
    if(isPalindrome(&n1)){
        cout << "List is a palindrome!";
    } else {
        cout << "List is NOT a palindrome!";
    }
    return 0;
}
