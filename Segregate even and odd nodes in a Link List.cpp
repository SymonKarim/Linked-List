//Segregate even and odd nodes in a Link List
//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
       Node* temp = head;
       Node* even = new Node(-1);
       Node* odd = new Node(-1);
       Node* eHead = even, * oHead = odd;
       while(temp){
          int data = temp->data;
          Node* newNode= NULL;
          if(data&1){
              newNode = new Node(data);
              odd->next = newNode;
              odd = newNode;
          }
          else {
              newNode = new Node(data);
              even->next = newNode;
              even = newNode;
          }
          temp = temp->next;
       }
     if(oHead->next) oHead= oHead->next;
     if(oHead->data!=-1) even->next = oHead;
      return eHead->next;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends
