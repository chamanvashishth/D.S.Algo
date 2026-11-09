from collections import deque
from typing import List


class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        prefix_sum = [0]

        for num in nums:
            prefix_sum.append(prefix_sum[-1] + num)

        candidates = deque()
        shortest_length = len(nums) + 1

        for i, current_sum in enumerate(prefix_sum):
            while candidates and current_sum - prefix_sum[candidates[0]] >= k:
                shortest_length = min(shortest_length, i - candidates.popleft())

            while candidates and prefix_sum[candidates[-1]] >= current_sum:
                candidates.pop()

            candidates.append(i)

        return shortest_length if shortest_length <= len(nums) else -1
