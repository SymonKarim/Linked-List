/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head, int k,int cnt) {
        if(head == NULL  ) return NULL;
        if(cnt<k) return head;
        int n = 0;
        ListNode* curr = head;
        ListNode* forward = NULL;
        ListNode *prev = NULL;
        while(n<k and curr!=NULL){
           forward = curr->next;
           curr->next = prev;
           prev = curr;
           curr = forward;
           n++;

        }
        if(forward !=NULL) head->next = reverse(forward,k,cnt-k);
        return prev;
    }
    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
    int cnt = 0;
    ListNode* temp = head;
    while(temp!=NULL){
        cnt++;
        temp = temp->next;
    } 
    head =  reverse(head, k,cnt);
      return head;
    }
};
