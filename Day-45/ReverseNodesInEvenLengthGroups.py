# Definition for singly-linked list:
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseEvenLengthGroups(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = head
        group_size = 2

        while prev.next:
            curr = prev.next
            count = 0

            while curr and count < group_size:
                curr = curr.next
                count += 1

            if count % 2 == 0:
                current = prev.next
                previous = curr

                for _ in range(count):
                    next_node = current.next
                    current.next = previous
                    previous = current
                    current = next_node

                tail = prev.next
                prev.next = previous
                prev = tail

            else:
                for _ in range(count):
                    prev = prev.next

            group_size += 1

        return head
