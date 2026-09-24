class Solution:
    def digitSum(self, n : int):
        s = str(n)
        a = 0
        for i in range(len(s)):
            a+= int(s[i])
        return a
    def smallestIndex(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(0,n,1):
            if(i == self.digitSum(nums[i])):
                return i
        return -1           