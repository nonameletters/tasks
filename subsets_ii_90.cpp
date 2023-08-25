class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        sort(begin(nums), end(nums));
        result.push_back(vector<int>());
        result.push_back(vector<int>(1, nums[0]));
        
        int new_born = 1;
        for(size_t i = 1; i  < nums.size(); i++)
        {       
            vector<vector<int>>::iterator it;
            if(nums[i] == nums[i - 1])
            {
                it = end(result) - new_born;
            }
            else
            {
                it = begin(result);
            }

            new_born = 0;
            vector<vector<int>> tmp(it, end(result));
            for (auto it_in = begin(tmp); it_in != end(tmp); it_in++)
            {
                it_in->push_back(nums[i]);
                new_born++;
            }
            result.insert(end(result), begin(tmp), end(tmp));
        }
        
        return result;
    }
};
