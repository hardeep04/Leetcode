class Solution:
    def runningSum(self, nums: list[int]) -> list[int]:
        a=[]
        for v in nums:
            if(len(a)==0):
                a.append(v)
            else:
                a.append(a[-1] + v)
        return a