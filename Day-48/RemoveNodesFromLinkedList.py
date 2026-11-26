from __future__ import annotations
from typing import Optional

# ListNode is provided by LeetCode.

class Solution:
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:

        def reverse(node):
            prev = None

            while node:
                next_node = node.next
                node.next = prev
                prev = node
                node = next_node

            return prev

        head = reverse(head)
        curr = head
        max_value = head.val

        while curr.next:
            if curr.next.val < max_value:
                curr.next = curr.next.next
            else:
                curr = curr.next
                max_value = curr.val

        return reverse(head)
