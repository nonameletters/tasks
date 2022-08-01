class MinStack {
private:
    vector<int> mainStk;
    vector<int> minStk;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (minStk.size() == 0) // Be carefull
        {
            minStk.push_back(val);
            mainStk.push_back(val);
            return; // If we not return from there. For the first value we put it twice in minStk. And wrong result occurs.
        }
        
        if (minStk.back() >= val)
            minStk.push_back(val);
        
        mainStk.push_back(val);
        
    }
    
    void pop() {
        int bk = mainStk.back();
        mainStk.pop_back();
        
        if (minStk.back() == bk)
            minStk.pop_back();
        
    }
    
    int top() {
        return mainStk.back();
    }
    
    int getMin() {
        return minStk.back();
    }
};
