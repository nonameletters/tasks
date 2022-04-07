    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int curSum = INT_MIN;
        for(size_t i = 0; i < nums.size(); i++)
        {
            if ((curSum <= 0) && (nums[i] < curSum))
            {
                continue;
            }
            else if ((curSum <= 0) && (nums[i] >= curSum))
            {
                curSum = nums[i];
            }
            else
            {
                curSum += nums[i];
            }
            
            if (curSum > maxSum)
                maxSum = curSum;  
            
        }
        return maxSum;
    }
