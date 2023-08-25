//{ Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
Node* mergeRec(Node* a, Node* b){
    if(!a) return b;
    if(!b) return a;
    
    if(a->data <= b->data){
        a->next = mergeRec(a->next,b);
    }else b->next = mergeRec(a,b->next);
}
Node* merge(Node* a, Node* b){
    Node* head = new Node(-1);
    Node* temp = head;
    while(a and b){
        if(a->data <=b->data){
            Node* nw = new Node(a->data);
            head->next = nw;
            head = nw;
            a = a->next;
            head->next = NULL;
        }else{
            Node* nw = new Node(b->data);
            head->next = nw;
            head = nw;
            b = b->next;
            head->next = NULL;
        }
    }
    if(a) head->next = a;
    if(b) head->next = b;
    return temp->next;
}
Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    Node* root = merge(head1, head2);
    return root;
}  
