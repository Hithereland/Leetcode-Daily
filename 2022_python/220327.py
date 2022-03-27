#
# created by z on 3/27/2022
# 1337

class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:

        s: List[List[int]] = [[0 ] *2 for _ in range(len(mat))] # python is weird
        for i in range(len(mat)):
            num: int = 0
            for j in range(len(mat[0])):
                if mat[i][j] == 1:
                    num += 1
                else:
                    break
            s[i][0] = num
            s[i][1] = i

        # There's no way to compare two or more values in one go in python3
        # The solution is to sort two times

        s.sort(key=lambda x: x[1])
        s.sort(key=lambda x: x[0])

        ret: List[int] = [0] * k
        for i in range(k):
            ret[i] = s[i][1]
        return ret

