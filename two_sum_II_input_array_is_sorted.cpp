// ---------- ---------- ---------- ----------
// Two pointers solution. It is used because array is sorted.
// It is best solution.
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int diff = 0;
        vector<int> res;
        int left = 0;
        int right = numbers.size() - 1;
        
        while(left < right)
        {
            int sum = numbers[left] + numbers[right];
            if (sum == target)
            {
                res.push_back(left + 1);
                res.push_back(right + 1);
                return res;
            }
            else if (sum > target)
            {
                right--;
            }
            else
            {
                left++;
            }            
        }
        
        return res;
    }
};

// ---------- ---------- ---------- ----------
// Native solution. It is accepted
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
