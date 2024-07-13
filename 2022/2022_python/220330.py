#
# created by z on 3/30/2022
# 74

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rn: int = len(matrix)
        cn: int = len(matrix[0])

        l: int = 0
        r: int = rn * cn - 1

        while l <= r:
            m: int = int((l + r) / 2)
            # transform
            row: int = m // cn
            col: int = m % cn
            # judge
            x: int = matrix[row][col]
            if x < target:
                l = m + 1
            elif x > target:
                r = m - 1
            else:
                return True

        return False

