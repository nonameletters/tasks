class Solution {
public: 
    void printMap(const map<char, int>& mp, const char *mpName)
    {
        printf("MP name: %s\n", mpName);
        for(auto it = begin(mp); it != end(mp); it++)
        {
            printf("F: %c, S: %d\n", it->first, it->second);
        }
    }
    
    bool checkHach(const map<char, int>& str, const map<char, int>& templ)
    {
        //printf("Check Hach\n");
        //printMap(str, "TO CHECK");
        //printMap(templ, "TEMPLATE");
        bool check = false;
        for(auto it = begin(templ); it != end(templ); it++)
        {
            auto st_it = str.find(it->first);
            if ((st_it != end(str)) && (st_it->second >= it->second))
            {
                check = true;
            }
            else
            {
                check = false;
                break;
            }
        }
        return check;
    }
    
public:
    string minWindow(string s, string t) 
    {
        if (t.size() > s.size())
            return "";
        
        map<char, int> tt;
        map<char, int> st;
        for(size_t i = 0; i < t.size(); i++)
        {
            tt[t[i]] += 1;
            st[s[i]] += 1;
        }
        
        size_t l = 0;
        size_t r = t.size() - 1;
        
        string result = "";
        while(l <= r)
        {
            // printf("L %d R %d\n", l , r);
            // TODO: We don't need to check tt every time "r" is moved
            //       check only when st[r] is in "tt"
            bool check = checkHach(st, tt);
            
            if (check)
            {
                string sub = s.substr(l, (r - l) + 1);
                // printf("EQ SUB: %s\n", sub.c_str());
                if (strcmp(result.c_str(), "") == 0)
                {
                    result = sub;
                }
                else if (result.length() > sub.length())
                {
                    result = sub;
                }
                
                auto it = st.find(s[l]);
                it->second--;
                if (it->second <= 0)
                    st.erase(it);
                l++;
                
                continue;
            }

            if (r < s.size())
            {
                r++;
                st[s[r]] += 1;
            }
            else
            {
                auto it = st.find(s[l]);
                it->second--;
                if (it->second <= 0)
                    st.erase(it);
                
                l++;
                    
            }
        }
        
        return result;
    }
};
