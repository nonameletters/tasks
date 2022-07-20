class Solution {
public:
    // gcd - greatest common divider
    static int gcd(int a, int b) 
    {
	    if (b == 0)
		    return abs(a);
	    return gcd(b, a % b);
    }
    
    // The main idea of rotation is mod(index) operation is cyclical
    void rotate(vector<int>& nums, int k) {        
        
        int count = gcd(nums.size(), k);
        int st = 0;
        for(int i = 0; i < count; i++)
        {
            size_t mi = st;
            int tmp = nums[mi];
            do
            {
                mi += k;
                if (mi >= nums.size())
                {
                    mi = mi % nums.size();
                }
                int tmpc = nums[mi];
                nums[mi] = tmp;
                tmp = tmpc;
            }
            while(mi != st);
            st++;
        }
        
    }
};
