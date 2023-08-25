//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

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
class Data{
    public:
     int data;
     Node* row;
     Data(int v, Node* head){
         data = v;
         row = head; 
     }
};
class comp{
    public: 
    bool operator()(Data* a, Data* b) {
        return a->data > b->data;
    }
};
class Solution{
  public:
    Node * mergeKLists(Node *arr[], int K)
    {
           priority_queue<Data*, vector<Data*>, comp>minHeap;
           for(int i=0;i<K;i++){
               minHeap.push(new Data(arr[i]->data,arr[i]->next));
           }
           Node * ans = new Node(-1);
           Node* head = ans;
           while(!minHeap.empty()){
               Data* temp = minHeap.top();
               minHeap.pop();
               int val = temp->data;
               Node * row = temp->row;
               Node* nw = new Node(val);
               ans->next = nw;
               ans = nw;
               if(row){
                   minHeap.push(new Data(row->data,row->next));
               }
           }
           return head->next;
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends
