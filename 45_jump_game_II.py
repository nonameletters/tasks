class Solution:
    def jump(self, nums: List[int]) -> int:
        steps = 0
        i = 0 
        while i < len(nums) - 1:
            steps += 1
            if (i + nums[i] >= len(nums) - 1):
                break
            j = i + 1
            dmax = 0
            jmax = 0
            while j < len(nums) and j <= i + nums[i]:
                if j + nums[j] > dmax:
                    dmax = j + nums[j]
                    jmax = j
                j += 1
            i = jmax

        return steps 
