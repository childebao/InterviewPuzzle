/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    int ans = 0;
    
    void sumNumbers(TreeNode *root, int sum)
    {
        if (!root) {
            return;
        }
        
        if (!root->left && !root->right) {
            ans += sum * 10 + root->val;
            return;
        }
        
        sumNumbers(root->left, sum * 10 + root->val);
        sumNumbers(root->right, sum * 10 + root->val);

    }
    
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        ans = 0;
        sumNumbers(root, 0);
        return ans; 
        
    }
};