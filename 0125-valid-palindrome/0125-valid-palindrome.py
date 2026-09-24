class Solution:
    def isPalindrome(self, s: str) -> bool:
        n=len(s)
        l=0
        r=n-1
        while(l<r):
            while( l<n and s[l].isalnum() == 0):
                l+=1
            while(r>-1 and s[r].isalnum() == 0):
                r-=1
            if(l<n and r>-1 and s[l].lower() != s[r].lower()):
                return False
            l+=1
            r-=1
        return True
        