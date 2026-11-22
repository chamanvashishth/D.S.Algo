from typing import List


class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = [-1] * n
        stack = []

        for i in range(2 * n):
            index = i % n

            while stack and nums[index] > nums[stack[-1]]:
                result[stack.pop()] = nums[index]

            if i < n:
                stack.append(index)

        return result
