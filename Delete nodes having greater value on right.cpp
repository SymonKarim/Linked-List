//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    Node* reverse(Node* head){
        Node* curr = head, *prev = NULL, *next = NULL;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr; 
            curr = next;
        }
        return prev;
    }
    public:
    Node *compute(Node *head)
    {
       if(!head or !head->next) return head;
       head = reverse(head);
       Node* nw = head;
       Node* temp = head->next,*ans = nw;
       while(temp){
           if(nw->data<=temp->data){
               nw->next = temp;
               nw = temp;
           }
           temp= temp->next;
       }
       nw->next = NULL;
       head = reverse(ans);
       return head;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends
