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
    ListNode* mid(ListNode* head){
        ListNode* slow = head, *fast = head->next;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }return slow;
    }
ListNode* reverse(ListNode* head){
        ListNode* curr =head, *prev = NULL, *next = NULL;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }return prev;
    }
public:
    void reorderList(ListNode* head) {
        ListNode* tmp = mid(head);
        ListNode* tail= reverse(tmp);
        ListNode* first = head;
        ListNode* second = tail;
        while(first){
          ListNode* a = first -> next;
          ListNode* b = second -> next;
            first->next = second;
            second->next = a;
            first = a;
            second = b;
        }
       
    }
};
