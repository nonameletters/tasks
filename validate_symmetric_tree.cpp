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
public:
    bool isSym(TreeNode* left, TreeNode* right)
    {
        if (!left && !right)
        {
            return true;
        }
        else if (left && right)
        {
            if (left->val != right->val)
            {
                return false;
            }
            else
            {
                bool lr = isSym(left->left, right->right);
                bool rr = isSym(left->right, right->left);
                return lr&&rr;
            }
            
        }
        else
        {
            return false;
        }
        
    }
    
public:
    bool isSymmetric(TreeNode* root) {
        return isSym(root->left, root->right);   
    }
};
