#This solution is 2 ms. Improove it
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        i = 0
        j = 0

        if len(s) == 0:
            return True
            
        while j < len(t):
            if i >= len(s):
                return True
            elif s[i] == t[j]:
                i += 1
                j += 1
                if i >= len(s) and j >= len(t):
                    return True
            else:
                j += 1

        return False
