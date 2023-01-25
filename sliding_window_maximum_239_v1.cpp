class Solution {
public:

    void print_queue(deque<int> &queue)
    {
        for(int i = 0; i < queue.size(); i++)
        {
            printf("%d ", queue.at(i));
        }
        printf("\n");
    }
    
    void put_to_queue(deque<int> &queue, int val)
    {
        while(!queue.empty() && (val > queue.back()))
        {
            queue.pop_back();
        }

        if (queue.empty())
        {
            queue.push_back(val);
            return;
        }

        while(!queue.empty() && (val > queue.front()))
        {
            queue.pop_front();
        }
 
        queue.push_front(val);
    }
    
    void rm_from_queue(deque<int> &queue, int val)
    {
        if (!queue.empty() && queue.back() == val)
        {
            queue.pop_back();
            return;
        }

        if (!queue.empty() && queue.front() == val)
        {
            queue.pop_front();
        }
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> queue;
        vector<int> result;

        int i = 0;        
        for(;i < k; i++)
        {
            put_to_queue(queue, nums[i]);
        }

        for(;i < nums.size(); i++)
        {
            result.push_back(queue.back());

            if (nums[i-k] != nums[i-1] || ((i-k) == (i-1)))
            {
                rm_from_queue(queue, nums[i - k]);
            }

            put_to_queue(queue, nums[i]);

        }

        result.push_back(queue.back());
        return result;    
    }
};
