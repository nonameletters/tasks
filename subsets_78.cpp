class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back(vector<int>());
        
        for(auto it = begin(nums); it != end(nums); it++)
        {
            vector<vector<int>> tmp = result;
            for(auto in_it = begin(tmp); in_it != end(tmp); in_it++)
            {
                in_it->push_back(*it);
            }
            result.insert(end(result), begin(tmp), end(tmp));
        }
        return result;
    }
};
