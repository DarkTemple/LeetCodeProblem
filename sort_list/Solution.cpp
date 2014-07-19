/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* 使用快慢指针的方法来找到中间节点更高效 */
class Solution {
public:
    ListNode *mergeTwoList(ListNode *h1, ListNode *h2) {
        ListNode *assistHead = new ListNode(0);
        ListNode *curHead = assistHead;
        while (h1 && h2) {
            if (h1->val <= h2->val) {
                curHead->next = h1;
                curHead = h1;
                h1 = h1->next;
            } else {
                curHead->next = h2;
                curHead = h2;
                h2 = h2->next;
            }
        }

        if (h1) curHead->next = h1;
        if (h2) curHead->next = h2;
        ListNode *head = assistHead->next;
        delete assistHead;
        return head;
    }

    ListNode *mergeSort(ListNode *head, int n) {
        if (n <= 1) return head;
        ListNode *h1 = head;
        int len = n/2;
        ListNode *h2 = head;
        ListNode *preNode = head;
        for (int i=0; i<len; i++) {
            if (i == len-1) preNode = h2;
            h2 = h2->next;
        }

        preNode->next = NULL;
        h1 = mergeSort(h1, len);
        h2 = mergeSort(h2, n-len);
        return mergeTwoList(h1, h2);
    }

    ListNode *sortList(ListNode *head) {
        int n = 0;
        ListNode *curNode = head;
        while (curNode) {
            n++;
            curNode = curNode->next;
        }

        return mergeSort(head, n);
    }
};