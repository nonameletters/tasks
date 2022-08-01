class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        size_t k = nums1.size() - 1;
        int i = m - 1;
        int j = nums2.size() - 1;
        
        while ((i >= 0) && (j >= 0))
        {
            printf("i %d j %d k %d\n", i, j, k);
            if (nums1[i] > nums2[j])
            {
                nums1[k] = nums1[i];
                k--;
                i--;
            }
            else
            {
                nums1[k] = nums2[j];
                k--;
                j--;
            }
            
        }
        
        while ((k >= 0) && (j >= 0))
        {
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
};
