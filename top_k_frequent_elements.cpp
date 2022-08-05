class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> count;
        for(size_t i = 0; i < nums.size(); i++)
        {
            count[nums[i]]++;
        }
        
        vector<set<int>> bucket(nums.size() + 1);
        for(auto i = begin(count); i != end(count); i++)
        {
            bucket[i->second].insert(i->first);   
        }
        
        vector<int> res;
        for(size_t i = bucket.size() - 1; i >= 0 && k > 0; i--)
        {
            if (!bucket[i].empty())
            {
                for(auto j = begin(bucket[i]); j != end(bucket[i]); j++)
                {
                    res.push_back(*j);
                    k--;
                }                
            }
        }
        
        return res;
    }
};
