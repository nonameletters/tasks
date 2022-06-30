/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void buildTree(vector<int>& nums, TreeNode* node, size_t but, size_t top)
    {
        // printf("but = %d, top = %d\n", but, top);
        if (but == top)
        {
            node->val = nums[but];
            return;
        }
        
        size_t ind = but + (top - but) / 2;
        // printf("ind = %d\n", ind);
        node->val = nums[ind];
        size_t ind_next = ind > but ? ind - 1 : but;
        if (but != ind_next || ind_next != ind)
        {
            node->left = new TreeNode();
            buildTree(nums, node->left, but, ind_next);
        }
        
        ind_next = ind < top ? ind + 1 : top;
        if (top != ind_next || ind_next != ind)
        {
            node->right = new TreeNode();
            buildTree(nums, node->right, ind_next, top);
        }
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = new TreeNode();
        buildTree(nums, root, 0, nums.size()-1);
        return root;
    }
};
