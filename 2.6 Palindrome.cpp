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

ListNode* isPalindromeAux(ListNode* head, ListNode* itr){
    if(!itr->next) { 
        if(head->val == itr->val){  // compare first to last
            return head->next;      // if equal return element next to head
        }
        else{
            return NULL;
        }
    }
    
    ListNode* next = isPalindromeAux(head, itr->next);
    if(!next){   // not equal
        return NULL;
    }
    // compare inner nodes
    if(next->val == itr->val){
        return next->next;
    } else {
        return NULL;
    }
    
}

bool isPalindrome(ListNode* head){
    if(!head || !head->next){ // Empty list or one element
        return true;   
    }
    ListNode* ret = isPalindromeAux(head,head->next);
    return ret == NULL? false : true;
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
