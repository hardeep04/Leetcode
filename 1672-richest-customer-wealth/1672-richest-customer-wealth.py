class Solution:
    def maximumWealth(self, v: list[list[int]]) -> int:
        maxi=0
        for i in range(len(v)):
            temp=0
            for j in range(len(v[0])):
                temp+=v[i][j]
            maxi = max(maxi, temp)
        return maxi