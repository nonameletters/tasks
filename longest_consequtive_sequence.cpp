class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // [100 4 200 1 3 2] - ex.
        // [...x 1 2 3 4 ...x 100 ... x 200]
        // nums[i] - 1 = x not exist in SET it mean nums[i] the begining of sequence
        set<int> snums(nums.begin(), nums.end());
        int length = 0;
        for(size_t i = 0; i < nums.size(); i++)
        {
            if (snums.find(nums[i] - 1) == snums.end())
            {
                int curLen = 0;
                auto it = snums.find(nums[i] + curLen);
                while( it != snums.end())
                {
                    curLen++;
                    snums.erase(it); // We had to remove element from set to lower search;
                                     // Not erasing element I got time limit;
                    it = snums.find(nums[i] + curLen);
                }
                
                if (curLen > length)
                    length = curLen;
            }
                
        }
        
        return length;
    }
};
