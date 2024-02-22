class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        res = []
        for elem in nums:
            if len(res) == 0:
                res.append(elem)
            elif res[-1] == elem:
                res.append(elem)
            else:
                res.pop()
        
        return res[-1] 
