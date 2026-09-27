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
    void reorderList(ListNode* head) {
        ListNode dummy(0,head);
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        
        // cut
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* second = slow->next;
        slow->next = nullptr;
        
        // reverse
        ListNode* pre = nullptr;
        
        while(second) {
            ListNode* next = second->next;
            second->next = pre;
            pre = second;
            second = next;
        }
        second = pre;

        // merge
        ListNode* first = head;
        while(second) {
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;
            first->next = second;
            second->next = t1;
            first = t1;
            second = t2;
        }
        

    }
};
