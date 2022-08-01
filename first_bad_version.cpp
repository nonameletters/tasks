class Solution {
public:
    int check(int left, int right)
    {
        if (right - left <= 1)
            return isBadVersion(left) ? left : right;        
        
        int mid = left + (right - left) / 2;
        
        if (isBadVersion(left) && isBadVersion(mid) && isBadVersion(mid+1) && isBadVersion(right))
            return left;
        
        if (!isBadVersion(left) && (isBadVersion(mid)))
            return check(left, mid);   
        else if (!isBadVersion(mid) && (isBadVersion(mid + 1)))
            return check(mid, mid + 1);
        else
            return check(mid+1, right);
    }
    
    int firstBadVersion(int n) {
        return check(1, n);
    }
};
