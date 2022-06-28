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
    bool checkNode(TreeNode* node, int &min, int &max)
    {
        if (node == nullptr)
            return true;
        int leftMin, leftMax;
        bool leftRes = checkNode(node->left, leftMin, leftMax);
        
        int rightMin, rightMax;
        bool rightRes = checkNode(node->right, rightMin, rightMax);
        
        if (!leftRes || !rightRes)
        {
            return false;
        }
        
        if ((node->left == nullptr) && (node->right == nullptr))
        {
            min = node->val;
            max = node->val;
            return true;
        }
        else if (node->left == nullptr)
        {
            if ((node->val < node->right->val) && (node->val < rightMin))
            {
                min = node->val;
                max = rightMax;
                return true;
            }
            
            return false;
        }
        else if (node->right == nullptr)
        {
            if ((node->val > node->left->val) && (node->val > leftMax))
            {
                min = leftMin;
                max = node->val;
                return true;
            }
            
            return false;
        }
        else
        {
            if ((node->val > node->left->val) && (node->val < node->right->val) &&
                (node->val > leftMax) && (node->val < rightMin))
            {
                min = leftMin;
                max = rightMax;
                return true;
            }
            return false;
        }
    }
    
public:
    bool isValidBST(TreeNode* root) {
        int min, max;
        return checkNode(root, min, max);
     }
};
