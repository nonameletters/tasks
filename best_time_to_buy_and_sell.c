    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int diff = 0;
        for(auto i = 0; i + 1 < prices.size(); i++)
        {
            if (prices[i] < min)
            {
                min = prices[i];
            }
            
            if (prices[i + 1] - min > diff)
            {
                diff = prices[i + 1] - min;
            }
        }
        
        return diff;
        
    }
