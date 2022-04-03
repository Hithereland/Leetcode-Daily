#
# created by z on 4/3/2022
# 31

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n: int = len(nums)
        if n == 1:
            return

        op: int = n - 1
        while op > 0 and nums[op - 1] >= nums[op]:
            op -= 1

        if op != 0:
            ex: int = op
            while ex < n and nums[op - 1] < nums[ex]:
                ex += 1

            nums[op - 1], nums[ex - 1] = nums[ex - 1], nums[op - 1]

        nums[op:] = sorted(nums[op:])
        return

