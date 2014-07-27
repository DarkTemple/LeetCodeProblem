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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *prev = head;
        while (prev && prev->next) {
            if (prev->val == prev->next->val) {
                ListNode *deleteNode = prev->next;
                prev->next = prev->next->next;
                delete deleteNode;
            } else {
                prev = prev->next;
            }
        }
        
        return head;
    }
};