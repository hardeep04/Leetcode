class Solution:
    def reverseString(self, s: list[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        n=len(s)
        for i in range(n//2):
            a = s[n-i-1]
            s[n-i-1] = s[i]
            s[i]=a