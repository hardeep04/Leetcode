class Solution:
    def maximumWealth(self, v: list[list[int]]) -> int:
        maxi=0
        for i in range(len(v)):
            maxi = max(maxi, sum(v[i]))
        return maxi