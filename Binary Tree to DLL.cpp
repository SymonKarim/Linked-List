class Solution
{ 
    
    public: 
    //Function to convert binary tree to doubly linked list and return it.
   // inOrder traversal kore DLL banano, left r right, next r prev er moto kaj korbe
    Node* prev = NULL;
    Node * bToDLL(Node *root)
    {
       if(!root) return NULL;
       Node* head = bToDLL(root->left);
       if(prev==NULL) head = root;
       else {
           root->left = prev;
           prev->right= root;
       }
       prev = root;
       bToDLL(root->right);
       return head;
    }
};
