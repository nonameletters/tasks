class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int diff = 0;
        vector<int> res;
        
        for(int i = 0; i < numbers.size(); i++)
        {
            if (i > 0 && numbers[i] == numbers[i - 1])
                continue;
            
            res.push_back(i+1);
            diff = target - numbers[i];
            int j = i + 1;
            while(j < numbers.size() && numbers[j] < diff)
            {
                j++;
            }
            
            if (j < numbers.size() && numbers[j] == diff)
            {
                res.push_back(j+1);
                break;
            }
            else
            {
                res.clear();
            }
            
        }
        
        return res;
    }
};
