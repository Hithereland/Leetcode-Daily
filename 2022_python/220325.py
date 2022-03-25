#
# created by z on 3/25/2022
# 1029

class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        costs.sort(key=lambda a: a[0] - a[1])
        ret: int = 0
        half: int = len(costs) / 2
        for i in range(len(costs)):
            ret += costs[i][i >= half]
        return ret