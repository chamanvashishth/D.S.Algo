class Solution:
    def reverseList(self, head):
        prev = None
        current = head

        while current:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node

        return prev

    def reverseListRecursive(self, head):
        if not head or not head.next:
            return head

        new_head = self.reverseListRecursive(head.next)
        head.next.next = head
        head.next = None

        return new_head
