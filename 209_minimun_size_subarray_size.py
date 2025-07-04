class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        li = ri = 0
        cur_sum = nums[0]
        min_len = len(nums) + 1

        while (li < len(nums) or ri < len(nums)):
            if cur_sum >= target:
                distance = ri - li + 1
                if distance == 1:
                    return distance
                
                if min_len > distance:
                    min_len = distance
                
                cur_sum -= nums[li]
                li += 1
            else:
                ri += 1
                if (ri >= len(nums)):
                    break
                cur_sum += nums[ri]
    
        if (min_len >= len(nums) + 1):
            return 0
        else:
            return min_len
