// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
// The simpliest solution. In leetcode we get Time Limint exception.
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

// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
// The simpliest solution with memorization. In some cases we enter to the same position.
// This means we don't need to recalculate this position. We save position state in to 
// the array.
    vector<int>* steps;
    int rob(vector<int>& nums) 
    {
        steps = new vector<int>(nums.size(), -1);
        return rh(nums, 0);    
    }
    
    int rh(vector<int>& nums, int i)
    {
        if (i == nums.size() - 1)
            return nums[i];
        else if (i >= nums.size())
            return 0;
        if ((*steps)[i] != -1)
            return (*steps)[i];
        
        int sum_i2 = rh(nums, i+2);
        int sum_i1 = rh(nums, i+1);
        if (nums[i] + sum_i2 >= sum_i1)
        {
            (*steps)[i] = nums[i] + sum_i2;
            // return nums[i] + sum_i2;
        }
        else
        {
            (*steps)[i] = sum_i1;
            // return sum_i1;
        }
        return (*steps)[i];
    }
