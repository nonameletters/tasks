    int rob(vector<int>& nums) 
    {
        return rh(nums, 0);    
    }
    
    int rh(vector<int>& nums, int i)
    {
        if (i == nums.size() - 1)
            return nums[i];
        else if (i >= nums.size())
            return 0;
        
        int sum_i2 = rh(nums, i+2);
        int sum_i1 = rh(nums, i+1);
        if (nums[i] + sum_i2 >= sum_i1)
            return nums[i] + sum_i2;
        else
            return sum_i1;
    }
