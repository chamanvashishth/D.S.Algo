class Solution:
    def reverseBetween(self, head, left, right):
        dummy = ListNode(0, head)
        prev = dummy

        # Move prev to the node just before the section to reverse
        for _ in range(left - 1):
            prev = prev.next

        current = prev.next

        # Move each next node to the front of the reversing section
        for _ in range(right - left):
            node = current.next
            current.next = node.next
            node.next = prev.next
            prev.next = node

        return dummy.next
