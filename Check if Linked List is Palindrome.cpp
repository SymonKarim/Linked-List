//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
#include<vector>
class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node* midFind(Node* head){
        Node* fast = head->next, *slow = head;
        while(fast and fast->next){
            slow= slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node* reverse(Node* head){
        Node* prev = NULL, *curr = head, *next = curr;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr= next;
            
        }
        head = prev;
        return head;
    }
    bool isPalindrome(Node *head)
    {
       if(!head->next) return true;
       Node* mid = midFind(head);
       Node* first = head;
       Node* second = reverse(mid->next);
       while(first and second){
           if(first->data !=second->data) return false;
           first= first->next;
           second = second->next;
       }
        return 1;
       
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends
