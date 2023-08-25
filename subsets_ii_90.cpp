/*
* First we need to sort array to rearrage all equail nums successively 
* ex: [4,4,4,1,4] -> [1,4,4,4,4]
* Then we use backtacking as in task 78. Main diffirence is that when we meet
* the same number it is nessecary to skip numbers that we generatet by the same previous number
* `new_born` value counts newly generated values. Then we take tail generated values.
*/
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
