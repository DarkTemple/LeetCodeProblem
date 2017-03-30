# You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
#
# You may assume the two numbers do not contain any leading zero, except the number 0 itself.
#
# Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
# Output: 7 -> 0 -> 8
#
# Subscribe to see which companies asked this question.

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        c = 0
        pre_node = None
        head_node = None
        while l1 or l2 or c:
            d = (l1.val if l1 else 0) + (l2.val if l2 else 0) + c
            c = d / 10
            d %= 10
            node = ListNode(d)
            if not pre_node:
                head_node = node
            else:
                pre_node.next = node

            pre_node = node
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None

        return head_node


if __name__ == "__main__":
    s = Solution()
    print s.addTwoNumbers(None, None)
