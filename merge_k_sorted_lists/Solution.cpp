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
    ListNode *merge2List(ListNode *l1, ListNode *l2) {
        ListNode *assistHead = new ListNode(0);
        ListNode *prev = assistHead;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            
            prev = prev->next;
        }
        
        if (l1) prev->next = l1;
        if (l2) prev->next = l2;
        return assistHead->next;
    }
    
    ListNode *mergeKListsHelper(vector<ListNode *> &lists, int start, int end) {
        if (start > end) return NULL;
        if (start == end) return lists[start];
        int mid = (start + end) / 2;
        ListNode *l1 = mergeKListsHelper(lists, start, mid);
        ListNode *l2 = mergeKListsHelper(lists, mid+1, end);
        return merge2List(l1, l2);
    }
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return mergeKListsHelper(lists, 0, int(lists.size())-1);
    }
};