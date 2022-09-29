class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        bool result = false;
        if (s1.size() > s2.size())
            return result;
        
        map<char, int> temp;
        for(size_t i = 0; i < s1.size(); i++)
        {
            temp[s1[i]] = temp[s1[i]] + 1;
        }
        
        for(size_t i = 0; i + s1.size() <= s2.size(); i++)
        {
            map<char, int> check = temp;
            
            for(size_t j = i; j < i + s1.size(); j++)
            {
                auto it = check.find(s2[j]);
                if (it == check.end())
                {
                    break;
                }
                else
                {   
                    it->second = (it->second) - 1;
                    
                    if (it->second <= 0)
                    {
                        check.erase(it);
                    }
                }
            }
            
            if(check.size() == 0)
                return true;
        }
        return result;
    }
};
