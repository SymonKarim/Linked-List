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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head, *slow = head;
        bool yes = 0;
        while(fast!=NULL and slow!=NULL and fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow) {
                yes = 1;break;
            }
        }
        if(!yes) return NULL;
        slow = head;
        int cnt = 0;
        while(fast!=slow){
            fast = fast->next;
            slow = slow->next;
            cnt++;
        }
        return slow;
    }
};
