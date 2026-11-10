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

            for i in range(left, mid):
                while start < right and prefix_sum[start] - prefix_sum[i] < lower:
                    start += 1

                while end < right and prefix_sum[end] - prefix_sum[i] <= upper:
                    end += 1

                count += end - start

            merged = []
            i, j = left, mid

            while i < mid and j < right:
                if prefix_sum[i] <= prefix_sum[j]:
                    merged.append(prefix_sum[i])
                    i += 1
                else:
                    merged.append(prefix_sum[j])
                    j += 1

            merged.extend(prefix_sum[i:mid])
            merged.extend(prefix_sum[j:right])
            prefix_sum[left:right] = merged

            return count

        return merge_sort(0, len(prefix_sum))
