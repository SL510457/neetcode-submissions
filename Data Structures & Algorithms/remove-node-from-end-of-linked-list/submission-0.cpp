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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        int s = 0;
        while(cur) {
            s++;
            cur = cur->next;
        }

        n = s-n+1;
        cur = head;
        ListNode* connect;

        while(n > 1) {
            connect = cur;
            cur = cur->next;
            n--;
        }

        if(cur == head)
            head = cur->next;
        else
            connect->next = cur->next;
        
        return head;

    }
};
