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

    // flatten the subtree, return the last node...
    TreeNode* flattenSubtree(TreeNode *root) {
        if (!root) return root;
        
        if (!root->left && !root->right) return root;
        
        if (!root->left) return flattenSubtree(root->right);
        
        if (!root->right) {
            root->right = root->left;
            root->left = NULL; // Remember to set left child NULL here...
            return flattenSubtree(root->right);
        }
        
        TreeNode *tmpRightSubtree = root->right;
        root->right = root->left;
        root->left = NULL;  // Remember to set left child NULL here...
        flattenSubtree(root->right)->right = tmpRightSubtree;
        
        return flattenSubtree(tmpRightSubtree);
    }
    
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        while (root && root->left == NULL) root = root->right;
        
        if (root) {
            TreeNode* preRightSubtree = root->right;
            root->right = root->left;
            root->left = NULL;  // Remember to set left child NULL here...
            
            flattenSubtree(root->right)->right = preRightSubtree;
            
            if (preRightSubtree) flattenSubtree(preRightSubtree);
        }
    }
};