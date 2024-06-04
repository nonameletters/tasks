"""
I don't realy understand why.
we need to sort list in descending order
Ex: 6 5  3  1 0 Then find i that is lower or equal
    0 1 [2] 3 4
Result is i + 1 => 2 + 1 = 3 
Need to compare i + 1 with citations[i]
citations number, that will be Hirsh index.
"""
class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort(reverse = True)

        h_index = 0
        for i in range(0, len(citations)):
            if i + 1 <= citations[i]:
                h_index = i + 1
            else:
                break

        return h_index
