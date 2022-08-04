class Solution {
public:
    int missingNumber(vector<int>& nums) {
        float sum = (((float) nums.size())/2) * (nums.size() + 1); // There we caculate sum from 0 to n (nums.size)
                                                                   // We could do the same adding i to sum in a cycle.
        int res = 0;
        
        for (size_t i = 0; i < nums.size(); i++)
        {
            res += nums[i];
        }

        // As we know that all numbers are unique. Subraction from desired sum numbers that we have
        // returns us number that we are looking for.
        return (int) sum - res;
    }
};
