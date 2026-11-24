from typing import List

class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = [-1] * n
        stack = []

        for i in range(2 * n - 1, -1, -1):
            index = i % n

            while stack and stack[-1] <= nums[index]:
                stack.pop()

            if stack:
                result[index] = stack[-1]

            stack.append(nums[index])

        return result
