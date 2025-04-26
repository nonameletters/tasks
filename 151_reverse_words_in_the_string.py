# Very awful solution but it works
# need rework
class Solution:
    def reverseWords(self, s: str) -> str:
        rs = ""
        space = 0
        chars = 0
        words = 0
        o_str = ""
        for i in range(len(s) - 1, -1, -1):
            if s[i] == ' ':
                space = 1
            elif space == 0:
                o_str += s[i]
                words = 1
            elif space != 0:
                if words == 0:
                    o_str += s[i]
                    words = 1
                else:
                    o_str += " " + s[i]
                space = 0

        r_str = ""
        i = 0
        while i < len(o_str):
            j = i
            while j < len(o_str) and o_str[j] != " ":
                j += 1;

            k = j - 1
            while k >= i:
                r_str += o_str[k]
                k -= 1
            
            if j < len(o_str) and o_str[j] == " ":
                r_str += " "

            i = j + 1

        return r_str      

        
