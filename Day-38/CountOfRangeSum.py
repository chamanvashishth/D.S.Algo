from typing import List


class Solution:
    def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
        prefix_sum = [0]

        for num in nums:
            prefix_sum.append(prefix_sum[-1] + num)

        def merge_sort(left: int, right: int) -> int:
            if right - left <= 1:
                return 0

            mid = (left + right) // 2
            count = merge_sort(left, mid) + merge_sort(mid, right)

            start = end = mid

            for value in prefix_sum[left:mid]:
                while start < right and prefix_sum[start] - value < lower:
                    start += 1

                while end < right and prefix_sum[end] - value <= upper:
                    end += 1

                count += end - start

            prefix_sum[left:right] = sorted(prefix_sum[left:right])
            return count

        return merge_sort(0, len(prefix_sum))
