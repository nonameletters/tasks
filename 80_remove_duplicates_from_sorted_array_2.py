class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        result = 0
        count = 0
        back = 0
        for i in range(len(nums)):
            count += 1
            if (i + 1 < len(nums) and nums[i] == nums[i + 1]):
                continue
            elif (i + 1 < len(nums) and nums[i] != nums[i + 1]):
                if count > 2:
                    count = 2
                for j in range(count):
                    nums[back] = nums[i]
                    back += 1
                result += count
                count = 0
            else:
                if count > 2:
                    count = 2
                for j in range(count):
                    nums[back] = nums[i]
                    back += 1
                result += count
                count = 0
        print(f"res {result}")
        return result




                
