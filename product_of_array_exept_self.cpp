class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        res.push_back(1);
        for (int i = 0; i < nums.size() - 1; i++)
        {
            res.push_back(res[res.size() - 1] * nums[i]);
        }
        
        int post = 1;
        for (int i = res.size() - 1; i >=0; i--)
        {
            res[i] = res[i] * post;
            post *= nums[i];
        }        
        
        return res;
    }
};
