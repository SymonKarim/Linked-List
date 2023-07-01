/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };

 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL or head->next == NULL) return false;
        ListNode* fast = head, *slow = head;

        while(fast!=NULL and fast->next!=NULL and slow!= NULL){
            fast = fast->next->next;
            //fast = fast->next;
              slow= slow->next;
              if(slow == fast) return true;
        }
        if(fast == slow) return true;
        else return false;
    }
};
