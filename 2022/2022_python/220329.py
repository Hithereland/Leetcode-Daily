#
# created by z on 3/29/2022
# 287
# 220328.py doesn't exist

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        m: dict = {}
        for x in nums:
            if m.get(x) == None:
                m[x] = 1
            else:
                return x
        return -1