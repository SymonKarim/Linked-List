//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

Node* findMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node* merge(Node* left , Node* right){
   if(!right and left) return left; 
   if(!left and right) return right;
    
    Node* temp = new Node(-1);
    Node* ans = temp;
    while(left && right){
        if(left->data <= right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        }else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    // while(left){
    //         temp->next = left;
    //         temp = left;
    //         left = left->next;
    // }
    // while(right){
    //         temp->next = right;
    //         temp = right;
    //         right = right->next;
    // }
    if(left) temp->next = left;
    if(right) temp->next = right;
    ans = ans->next;
    return ans;
}
Node* mergesort(Node* head){
    if(!head or !head->next) return head;

    Node* mid = findMid(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    left = mergesort(left);
    right = mergesort(right);

    Node* result = merge(left, right);

    return result;
}
class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        return mergesort(head);
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends
