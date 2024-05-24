class Solution:
    def canJump(self, nums: List[int]) -> bool:
        i = 0
        if len(nums) == 1:
            return True

        while (i < len(nums)):
            if (nums[i] != 0):
                i += 1
                continue

            if (i == len(nums) -1):
                return True
                
            j = i - 1
            while (j >= 0):
                if (nums[j] + j <= i):
                    j -= 1
                else:
                    i += 1
                    break
            if (j < 0):
                return False
        return True

# Second solution better but not well
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        i = 0
        while i < len(nums):
            if i == len(nums) - 1:
                return True

            if nums[i] != 0:
                i += nums[i]
                continue

            j = i - 1
            while (j >= 0):
                if (nums[j] + j > i):
                    i = j + nums[j]
                    break
                else:
                    j -= 1
            if (j <= 0):
                return False
        return True
