#
# created by z on 4/1/2022
# 344

class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        n: int = len(s)
        for i in range(n//2):
            s[i], s[-1-i] = s[-1-i], s[i]
        return