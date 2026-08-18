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
    ListNode* reverseList(ListNode* head) {
        if(!head)    return NULL;

        ListNode* preNode = head;
        ListNode* curNode = head->next;
        preNode->next = NULL;
        
        while(curNode) {
            ListNode* nextNode = curNode->next;
            curNode -> next = preNode;
            preNode = curNode;
            curNode = nextNode;
        }

        return preNode;
    }
};
